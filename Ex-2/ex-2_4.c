#include <stdio.h>

#define N 3
int main() {
  int count = 1;
  int arr_4[N][N];

  printf("\n/--------Ex-2_4----------/\n");

  int top = 0, bottom = N - 1;
  int left = 0, right = N - 1;
  while (count <= N * N) {
    for (int i = left; i <= right; i++) {
      arr_4[top][i] = count++;
    }
    top++;

    for (int i = top; i <= bottom; i++) {
      arr_4[i][right] = count++;
    }
    right--;

    for (int i = right; i >= left; i--) {
      arr_4[bottom][i] = count++;
    }
    bottom--;

    for (int i = bottom; i >= top; i--) {
      arr_4[i][left] = count++;
    }
    left++;
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      printf("%d ", arr_4[i][j]);
    }
    printf("\n");
  }

  return 0;
}