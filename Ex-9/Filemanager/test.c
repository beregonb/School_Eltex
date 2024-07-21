#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <pthread.h>

// Структура для передачи аргументов в поток
typedef struct {
    char* dir_path;
    int thread_num;
    int go_up; // Флаг для указания, нужно ли выходить на уровень выше
} thread_args_t;

// Функция потока для чтения содержимого директории
void* read_directory(void* args) {
    thread_args_t* thread_args = (thread_args_t*)args;
    char* dir_path = thread_args->dir_path;
    int thread_num = thread_args->thread_num;
    int go_up = thread_args->go_up;
    int i = 1;

    // Смена директории на уровень выше, если это указано
    if (go_up) {
        if (chdir("..") != 0) {
            perror("chdir");
            pthread_exit(NULL);
        }
    }

    DIR* dr = opendir(dir_path);
    if (dr == NULL) {
        perror("opendir");
        pthread_exit(NULL);
    }

    printf("Contents of directory in thread %d:\n", thread_num);
    struct dirent* de;
    while ((de = readdir(dr)) != NULL) {
        printf("Thread %d - %d %s\n", thread_num, i, de->d_name);
        i++;
    }
    closedir(dr);

    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    thread_args_t args1 = {".", 1, 0}; // Работает в текущей директории
    thread_args_t args2 = {".", 2, 1}; // Работает в родительской директории

    // Создание первого потока
    if (pthread_create(&thread1, NULL, read_directory, (void*)&args1) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Создание второго потока
    if (pthread_create(&thread2, NULL, read_directory, (void*)&args2) != 0) {
        perror("pthread_create");
        return 1;
    }

    // Ожидание завершения потоков
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
