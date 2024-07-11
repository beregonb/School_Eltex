#include "functions.h"

void search_abonent(struct abonent *abon, int *count) {
  char name[10];
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
}