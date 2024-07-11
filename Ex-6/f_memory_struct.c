#include "functions.h"
/**
 * @brief Функция выделения памяти для структуры или ее расширения
 * 
 * @param abon Указатель на структуру
 * @param max_abonent_count Количество абонентов
 */
void memory_struct(struct abonent **abon, int max_abonent_count) {
  if (max_abonent_count == 1) {
    *abon =
        (struct abonent *)malloc(sizeof(struct abonent) * max_abonent_count);
  } else {
    *abon = (struct abonent *)realloc(
        *abon, sizeof(struct abonent) * max_abonent_count);
  }
  if (*abon == NULL) {
    printf("Память не выделена\n");
    exit(1);
  }
}