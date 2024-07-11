#include "functions.h"

void memory_abonent(struct abonent *abon, int count) {
  abon[count].name = (char *)malloc(sizeof(char) * 10);
  abon[count].second_name = (char *)malloc(sizeof(char) * 10);
  abon[count].tel = (char *)malloc(sizeof(char) * 10);
  if (abon[count].name == NULL || abon[count].second_name == NULL ||
      abon[count].tel == NULL) {
    printf("Память не выделена\n");
    exit(1);
  }
}
