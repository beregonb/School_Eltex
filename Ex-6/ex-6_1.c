#include "functions.h"

int main() {
  struct abonent *abon = NULL;
  int num, count = 0, max_abonent = 0;

  print_menu();
  scanf("%d", &num);

  while (num != 5) {
    switch (num) {
      case 1:
        printf("\nДобавление абонента\n");
        max_abonent++;
        memory_struct(&abon, max_abonent);
        memory_abonent(abon, count);
        plus_abonent(abon, &count);
        break;
      case 2:
        printf("Удаление абонента\n");
        delete_abonent(abon, &count);
        max_abonent--;
        memory_struct(&abon, max_abonent);
        break;
      case 3:
        printf("Поиск абонентов по имени\n");
        search_abonent(abon, &count);
        break;
      case 4:
        printf("Вывод всех записей\n");
        print_abonent(abon, count);
        break;
      case 5:
        printf("Выход\n");
        break;
      default:
        printf("ERROR. Incorrect input\n");
        break;
    }
    print_menu();
    scanf("%d", &num);
  }
  for (int i = 0; i < max_abonent; i++) {
    memory_abonent_free(&abon[i]);
  }

  free(abon);
  return 0;
}