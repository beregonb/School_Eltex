#include "functions.h"
/**
 * @brief Функция поиска абонента в телефонной книге
 * 
 * @param abon Указатель на структуру со всеми абонентами
 * @param count Количество имен в телефонной книге
 */
void search_abonent(struct abonent *abon, int *count) {
  char *name = (char *)malloc(sizeof(char) * 10);
  int flag = 1;
  printf("Введите имя абонента: ");
  scanf("%s", name);
  for (int i = 0; i < *count; i++) {
    if (strcmp(abon[i].name, name) == 0) {
      printf("Найден абонент: Имя: %s Фамилия: %s Телефон: %s\n", abon[i].name,
             abon[i].second_name, abon[i].tel);
      flag = 0;
    }
  }
  if (flag) {
    printf("Абонент не найден!!!\n");
  }
  free(name);
}