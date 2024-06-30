#include <stdio.h>
#include <string.h>

#define MAX_ABONENTS 100

struct abonent {
  char name[10];
  char second_name[10];
  char tel[10];
};

void prinft_menu() {
  printf(
      " 1. Добавить абонента\n 2. Удалить абонента\n 3. Поиск абонентов по "
      "имени\n 4. Вывод всех записей\n 5. Выход\n");
  printf("\nВведите пункт из меню: ");
}

void plus_abonent(struct abonent *abon, int *count) {
  if (*count < MAX_ABONENTS) {
    printf("Имя: ");
    scanf("%s", abon[*count].name);
    printf("Фамилия: ");
    scanf("%s", abon[*count].second_name);
    printf("Номер телефона: ");
    scanf("%s", abon[*count].tel);
    printf("Абонент добавлен!!!\n");
    (*count)++;
  } else {
    printf("Список полон!!!\n");
  }
}

void print_abonent(struct abonent *abon, int count) {
  if (count == 0) {
    printf("Список пуст!!!\n");
    return;
  }
  for (int i = 0; i < count; i++) {
    printf("Имя: %s Фамилия: %s Телефон: %s\n", abon[i].name,
           abon[i].second_name, abon[i].tel);
  }
}

void search_abonent(struct abonent *abon, int *count) {
  char name[10];
  int flag = 1;
  printf("Введите имя абонента: ");
  scanf("%s", name);
  for (int i = 0; i < *count; i++) {
    if (strcmp(abon[i].name, name) == 0) {
      printf("Найден абонент: Имя: %s Фамилия: %s Телефон: %s\n", abon[i].name,
             abon[i].second_name, abon[i].tel);
      flag = 0;
    }
  }
  if (flag) {
    printf("Абонент не найден!!!\n");
  }
}

void delete_abonent(struct abonent *abon, int *count) {
  char name[10];
  printf("Введите имя абонента: ");
  scanf("%s", name);

  int found = 0;
  for (int i = 0; i < *count; i++) {
    if (strcmp(abon[i].name, name) == 0) {
      for (int j = i; j < *count - 1; j++) {
        abon[j] = abon[j + 1];
      }
      (*count)--;
      printf("Абонент удален!!!\n");
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Абонент с именем %s не найден.\n", name);
  }
}

int main() {
  struct abonent abon[100];

  int num, count = 0;

  prinft_menu();
  scanf("%d", &num);

  while (num != 5) {
    switch (num) {
      case 1:
        printf("\nДобавление абонента\n");
        plus_abonent(abon, &count);
        break;
      case 2:
        printf("Удаление абонента\n");
        delete_abonent(abon, &count);
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
    }
    prinft_menu();
    scanf("%d", &num);
  }
  return 0;
}