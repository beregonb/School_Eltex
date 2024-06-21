#include "functions.h"

int main() {
  int num;
  printf("Enter negative integer number: ");
  if (scanf("%d", &num) != 1 && num > 0) {
    printf("ERROR. Incorrect input");
  }
  print_bit(num);
  return 0;
}