#include <stdio.h>

int main(void) 
{
    char n[] = {
        'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c',
        'r', 'r', 'r', 'r', 'r', 'r', 'r', 'r',
        0xd8, 0x11, 0x40, 0x00
    };

    FILE* file = fopen("input.txt", "w");
    if (file != NULL) {
        fprintf(file, "%s", n);
        fclose(file);
    } else {
        printf("Ошибка открытия файла.\n");
    }

    return 0;
}
