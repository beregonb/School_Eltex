#include <stdio.h>

#define N 3
int main() {
  int count = 1;

  printf("\n/--------Ex-2_1----------/\n");

  int arr[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      arr[i][j] = count;
      count++;
      printf("%d ", arr[i][j]);
    }

    printf("\n");
  }
  return 0;
}