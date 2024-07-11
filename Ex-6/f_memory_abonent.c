#include "functions.h"
/**
 * @brief Функция выделения памяти
 *
 * @param abon Указатель на структуру со всеми абонентами
 * @param count Порядковый номер абонента в структуре
 */
void memory_abonent(struct abonent *abon, int count) {
  abon[count].name = (char *)malloc(sizeof(char) * 10);
  abon[count].second_name = (char *)malloc(sizeof(char) * 10);
  abon[count].tel = (char *)malloc(sizeof(char) * 10);
  if (abon[count].name == NULL || abon[count].second_name == NULL ||
      abon[count].tel == NULL) {
    printf("Память не выделена\n");
    exit(1);
  }
}
