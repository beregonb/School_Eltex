#include "main.h"

void division() {
  int one_num, two_num, result;

  printf("Введите два целых числа для деления через пробел: ");
  if (scanf("%d %d", &one_num, &two_num) != 2 || one_num == 0 || two_num == 0) {
    printf("\nНекорректный ввод\n");
    while (getchar() != '\n')
      ;
    return;
  }

  result = one_num / two_num;
  printf("ИТОГО: %d / %d = %d\n", one_num, two_num, result);
}