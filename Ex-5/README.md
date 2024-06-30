1. Адрес возврата
![alt text](image-1.png)
2. Адрес строки "Access granted!" 0x402022
![alt text](<Screenshot from 2024-06-30 11-45-54.png>)
3. Адрес строки "Access granted!" это 0x402022. В формате little-endian это будет \x22\x20\x40\x00.
4. (echo -n -e "AAAAAAAAAAAA\x22\x20\x40\x00") > exploit.txt
5. ![alt text](image-2.png)