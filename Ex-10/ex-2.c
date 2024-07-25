#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void create_processes3_add4();
void create_processes5();

int main() {
  pid_t pid_1, pid_2;

  pid_1 = fork();

  if (pid_1 == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid_1 == 0) {
    printf("Дочерний процесс pid_1 = %d ppid_1 = %d\n", getpid(), getppid());
    create_processes3_add4();
    exit(EXIT_SUCCESS);
  } else {
    int status;
    waitpid(pid_1, &status, 0);
    if (WIFEXITED(status)) {
      printf("Дочерний процесс pid_1 %d завершился: %d\n", pid_1,
             WEXITSTATUS(status));
    } else {
      printf("Дочерний процесс pid_1 %d не завершился\n", pid_1);
    }
  }

  pid_2 = fork();

  if (pid_2 == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }

  if (pid_2 == 0) {
    printf("Дочерний процесс pid_2 = %d ppid_2 = %d\n", getpid(), getppid());
    create_processes5();
    exit(EXIT_SUCCESS);
  } else {
    int status;
    waitpid(pid_2, &status, 0);
    if (WIFEXITED(status)) {
      printf("Дочерний процесс pid_2 %d завершился: %d\n", pid_2,
             WEXITSTATUS(status));
    } else {
      printf("Дочерний процесс pid_2 %d не завершился\n", pid_2);
    }
  }

  return 0;
}

void create_processes3_add4() {
  pid_t pid_3, pid_4;

  pid_3 = fork();
  if (pid_3 == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid_3 == 0) {
    printf("Дочерний процесс pid_3 = %d ppid_3 = %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
  } else {
    int status;
    waitpid(pid_3, &status, 0);
    if (WIFEXITED(status)) {
      printf("Дочерний процесс pid_3 %d завершился: %d\n", pid_3,
             WEXITSTATUS(status));
    } else {
      printf("Дочерний процесс pid_3 %d не завершился\n", pid_3);
    }
  }

  pid_4 = fork();
  if (pid_4 == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid_4 == 0) {
    printf("Дочерний процесс pid_4 = %d ppid_4 = %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
  } else {
    int status;
    waitpid(pid_4, &status, 0);
    if (WIFEXITED(status)) {
      printf("Дочерний процесс pid_4 %d завершился: %d\n", pid_4,
             WEXITSTATUS(status));
    } else {
      printf("Дочерний процесс pid_4 %d не завершился\n", pid_4);
    }
  }
}

void create_processes5() {
  pid_t pid_5;

  pid_5 = fork();
  if (pid_5 == -1) {
    perror("fork");
    exit(EXIT_FAILURE);
  }
  if (pid_5 == 0) {
    printf("Дочерний процесс pid_5 = %d ppid_5 = %d\n", getpid(), getppid());
    exit(EXIT_SUCCESS);
  } else {
    int status;
    waitpid(pid_5, &status, 0);
    if (WIFEXITED(status)) {
      printf("Дочерний процесс pid_5 %d завершился: %d\n", pid_5,
             WEXITSTATUS(status));
    } else {
      printf("Дочерний процесс pid_5 %d не завершился\n", pid_5);
    }
  }
}
