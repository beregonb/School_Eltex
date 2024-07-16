#include "main.h"

int main() {
  int num;

  while (1) {
    print_menu();
    if (scanf("%d", &num) != 1) {
      printf("Некорректный ввод, попробуйте снова.\n");
      while (getchar() != '\n')
        ;
      continue;
    }

    if (num == 5) {
      break;
    }

    switch (num) {
      case 1:
        sum();
        break;
      case 2:
        sub();
        break;
      case 3:
        mul();
        break;
      case 4:
        division();
        break;
      default:
        printf("Некорректный ввод, попробуйте снова.\n");
        break;
    }
  }
  printf("-----Завершение программы-----\n");
}