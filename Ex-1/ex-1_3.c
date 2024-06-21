#include "functions.h"

int main() {
  int num;
  printf("Enter positive integer number: ");
  if (scanf("%d", &num) != 1 && num < 0) {
    printf("ERROR. Incorrect input");
  }
  sum_one_bits(num);
  return 0;
}