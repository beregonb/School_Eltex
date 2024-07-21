#include <stdio.h>
#include <stdlib.h>

int main() {
  char line[255];

  FILE *file = fopen("output.txt", "w");
  if (file == NULL) {
    perror("Ошибка при открытии файла для записи");
    return 1;
  }

  fprintf(file, "String from file");
  fclose(file);

  file = fopen("output.txt", "r");
  if (file == NULL) {
    perror("Ошибка при открытии файла для чтения");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  fread(line, 1, file_size, file);
  fclose(file);

  for (long i = file_size - 1; i >= 0; i--) {
    putchar(line[i]);
  }
  putchar('\n');

  return 0;
}
