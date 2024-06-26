#include <stdio.h>

#include "../Ex-1/functions.h"

int main() {
  int num;
  int a;
  char *ptr = NULL;

  if (scanf("%d", &num) == 1 && num > 0) {
    printf("Enter swap 3 bit number: ");
    if (scanf("%d", &a) == 1 && a > 0 && a < 256) {
      ptr = (char *)&num;
      ptr = ptr + 2;
      *ptr = a;
      print_bit(num);
      printf("Третий байт: %d\n", *ptr);
    } else {
      printf("ERROR. Number greater than 8 bits");
    }

  } else {
    printf("ERROR. Incorrect input");
  }
  return 0;
}