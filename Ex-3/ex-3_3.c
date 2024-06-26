#include <stdio.h>

int main() {
  int arr[10];
  int *ptr = arr;

  for (int i = 0; i < 10; i++) {
    arr[i] = i + 1;
  }
  for (int i = 0; i < 10; i++) {
    printf("%d ", *(ptr + i));
  }
  return 0;
}