#include <stdio.h>

#define N 3
int main() {
  int count = 1;
  int arr_2[N];

  printf("/--------Ex-2_2----------/\n");

  for (int i = 0; i < N; ++i) {
    arr_2[i] = count;
    count++;
  }

  for (int i = 0; i < N / 2; ++i) {
    int temp = arr_2[i];
    arr_2[i] = arr_2[N - 1 - i];
    arr_2[N - 1 - i] = temp;
  }

  for (int i = 0; i < N; ++i) {
    printf("%d ", arr_2[i]);
  }
  printf("\n");

  return 0;
}