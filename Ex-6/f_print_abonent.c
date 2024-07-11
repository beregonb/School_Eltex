#include "functions.h"
/**
 * @brief Функция вывода абонентов
 * 
 * @param abon Указатель на структуру со всеми абонентами
 * @param count Количество имен в телефонной книге
 */
void print_abonent(struct abonent *abon, int count) {
  if (count == 0) {
    printf("Список пуст!!!\n");
    return;
  }
  for (int i = 0; i < count; i++) {
    printf("Имя: %s Фамилия: %s Телефон: %s\n", abon[i].name,
           abon[i].second_name, abon[i].tel);
  }
}
