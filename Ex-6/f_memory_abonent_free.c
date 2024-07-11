#include "functions.h"

void memory_abonent_free(struct abonent *abon) {
  free(abon->name);
  free(abon->second_name);
  free(abon->tel);
}