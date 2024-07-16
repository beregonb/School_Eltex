#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ABONENTS 100

struct abonent {
  char *name;
  char *second_name;
  char *tel;
};

void print_menu();
void plus_abonent(struct abonent *abon, int *count);
void print_abonent(struct abonent *abon, int count);
void search_abonent(struct abonent *abon, int *count);
void delete_abonent(struct abonent *abon, int *count);

void memory_abonent(struct abonent *abon, int count);
void memory_struct(struct abonent **abon, int max_abonent_count);
void memory_abonent_free(struct abonent *abon);

#endif