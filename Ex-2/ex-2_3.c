#include <stdio.h>

#define N 3
int main() {
  int arr_3[N][N];

  printf("\n/--------Ex-2_3----------/\n");

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i + j >= N - 1) {
        arr_3[i][j] = 1;

      } else {
        arr_3[i][j] = 0;
      }
    }
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d ", arr_3[i][j]);
    }
    printf("\n");
  }

  return 0;
}