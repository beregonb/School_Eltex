#include <stdio.h>

char* parser(char* str, char* str_po) {
  char *ptr1, *ptr2, *ptr3;
  for (ptr1 = str; *ptr1 != '\0'; ptr1++) {
    ptr2 = ptr1;
    ptr3 = str_po;
    while (*ptr3 != '\0' && *ptr2 == *ptr3) {
      ptr2++;
      ptr3++;
    }
    if (*ptr3 == '\0') {
      return ptr1;
    }
  }
  return NULL;
}

int main() {
  char str[50];
  char str_pod[50];

  scanf("%s", str);
  scanf("%s", str_pod);

  char* ptr = parser(str, str_pod);
  printf("%s\n", ptr);

  return 0;
}