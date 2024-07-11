#include "functions.h"
/**
 * @brief Функция очистки памяти
 *
 * @param abon Указатель на структуру со всеми абонентами
 */
void memory_abonent_free(struct abonent *abon) {
  free(abon->name);
  free(abon->second_name);
  free(abon->tel);
}