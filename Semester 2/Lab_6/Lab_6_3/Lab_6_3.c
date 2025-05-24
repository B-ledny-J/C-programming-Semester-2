/*
* @file Lab_6_3.c
* @author Дарчук Г.С., 515i
* @date 23.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Рядки. Параметри командного рядку. Завдання 3
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "sds.h"

/*
 * Перевірка, чи є рядок mac коректною MAC-адресою (xx-xx-xx-xx-xx-xx, де xx – шістнадцяткове число);
 * якщо є, то видаляє з рядка усі дефіси та записує усі літерні шістнадцяткові цифри у верхньому регістрі
 *
 * @param old вихідний рядок
 * @param new оброблений рядок
 * @return 1, якщо перетворення успішне
 */
int process_MAC(sds mac) {
    int length = sdslen(mac);
    if(length != 17)
    {
        printf("Помилка: довжина адреси має дорівнювати 16 символам!");
        return 0;
    }
    for(int i = 0; i < 17; ++i)
    {
        char c = mac[i];
        if(((i + 1) % 3) == 0)
        {
            if(c != '-')
            {
                printf("Помилка: формат запису адреси невірний!\n");
                return 0;
            }
            continue;
        }
        if (!isxdigit(c))
        {
            printf("Помилка: формат запису адреси невірний!\n");
            return 0;
        }
        if(c >= 'a' && c <= 'f') c -= 'a' - 'A';
        mac[(i / 3) * 2 + i % 3] = c;
    }
    mac[12] = '\0';
    return 1;
}

int main() {
    sds mac = sdsnewlen(NULL, 17);
    char buffer[18];
    printf("Введіть mac-адресу:");
    scanf("%17s", buffer);
    sdscpy(mac, buffer);
    printf("Вигляд введеної mac-адреси: %s\n", mac);
    if(process_MAC(mac))
    {
        printf("Вигляд обробленої mac-адреси: %s\n", mac);
        sdsfree(mac);
        return 0;
    }
    sdsfree(mac);
    return 1;
}