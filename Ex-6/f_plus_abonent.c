#include "functions.h"
void plus_abonent(struct abonent *abon, int *count) {
  if (*count < MAX_ABONENTS) {
    printf("Имя: ");
    scanf("%s", abon[*count].name);
    printf("Фамилия: ");
    scanf("%s", abon[*count].second_name);
    printf("Номер телефона: ");
    scanf("%s", abon[*count].tel);
    printf("Абонент добавлен!!!\n");
    (*count)++;
  } else {
    printf("Список полон!!!\n");
  }
}