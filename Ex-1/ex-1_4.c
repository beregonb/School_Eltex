#include "functions.h"

int main() {
  int num;
  int swap_num;

  printf("Enter positive integer number: ");
  if (scanf("%d", &num) == 1 && num > 0) {
    print_bit(num);
    printf("Enter swap 3 bit number: ");
    if (scanf("%d", &swap_num) == 1 && swap_num > 0 && swap_num < 256) {
      num &= 0xFF00FFFF;
      num |= (swap_num << 16);
      print_bit(num);
    } else {
      printf("ERROR. Number greater than 8 bits");
    }
  } else {
    printf("ERROR. Incorrect input");
  }
}