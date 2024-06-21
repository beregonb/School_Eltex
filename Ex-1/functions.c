#include "functions.h"

void print_bit(int num) {
  int count = 0;
  for (int i = 31; i >= 0; --i) {
    int bit = (num >> i) & 1;
    printf("%d", bit);
    count++;
    if (count % 8 == 0) {
      printf(" ");
    }
  }
  printf("\n");
}

void sum_one_bits(int num) {
  int sum = 0;
  for (int i = 31; i >= 0; --i) {
    int bit = (num >> i) & 1;
    if (bit == 1) {
      sum += 1;
    }
  }
  printf("%d\n", sum);
}

void swap_bit(int num, int swap_num) {
  int num_temp;
  swap_num = swap_num << 16;
  num_temp = num ^ swap_num;
  print_bit(num_temp);
}
