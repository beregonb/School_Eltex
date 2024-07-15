#include "main.h"

void mul() {
  int one_num, two_num, result;

  printf("Введите два целых числа для умножения через пробел: ");
  if (scanf("%d %d", &one_num, &two_num) != 2) {
    printf("\nНекорректный ввод\n");
    while (getchar() != '\n')
      ;
    return;
  }

  result = one_num * two_num;
  printf("ИТОГО: %d * %d = %d\n", one_num, two_num, result);
}