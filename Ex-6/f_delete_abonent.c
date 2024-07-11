#include "functions.h"
/**
 * @brief Функция для удаления абонента из телефонной книги
 * 
 * @param abon Указатель на структуру со всеми абонентами
 * @param count Количество имен в телефонной книге
 */
void delete_abonent(struct abonent *abon, int *count) {
  if (*count != 0) {
    char *name = (char *)malloc(sizeof(char) * 10);
    printf("Введите имя абонента: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *count; i++) {
      if (strcmp(abon[i].name, name) == 0) {
        memory_abonent_free(&abon[i]);
        for (int j = i; j < *count - 1; j++) {
          abon[j] = abon[j + 1];
        }
        (*count)--;
        printf("Абонент удален!!!\n");
        found = 1;
        break;
      }
    }

    if (!found) {
      printf("Абонент с именем %s не найден.\n", name);
    }
    free(name);
  } else {
    printf("Список пуст!!!\n");
  }
}