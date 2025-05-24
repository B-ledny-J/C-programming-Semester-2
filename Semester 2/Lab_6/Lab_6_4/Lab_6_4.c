/*
* @file Lab_6_4.c
* @author Дарчук Г.С., 515i
* @date 23.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Рядки. Параметри командного рядку. Завдання 4
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "sds.h"
#include <stdlib.h>

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

void print_padded_with_max(sds str, int max_len) {
    int str_len = sdslen(str);
    printf("%.*s", str_len > max_len ? max_len - 3 : str_len, str);
    if(str_len > max_len) printf("...");
    else if(str_len < max_len) printf("% *c", max_len - str_len, ' ');
}

void process_one_mac(sds mac) {
    printf("| ");
    print_padded_with_max(mac, 20);
    printf(" | ");
    int result = process_MAC(mac);
    if(result) printf(mac);
    else print_padded_with_max(" ", 12);
    printf(" | ");
    printf("   %d  ", result);
    printf(" |\n");
}

int main(int argc, char** argv)
{
    for(int i = 1; i < argc; ++i)
    {
        if(strcmp(argv[i], "/?") == 0 || strcmp(argv[i], "-?") == 0)
        {
            printf("Usage: %s [mac1] [mac2] [mac...] [macN]\n", argv[0]);
            printf("Example: %s 00-00-00-00-00-00 ab-cd-ef-98-76-54", argv[0]);
            return 0;
        }
    }

    if(argc <= 1)
    {
        char line[128] = {0};
        int line_len = 0;
        if(fgets(line, 127, stdin) < 0)
        {
            printf("Failed to read line!\n");
            return 1;
        }

        printf("+---------input--------+----output----+-result-+\n");

        sds mac = sdsnew(line);
        sdstrim(mac, " \n\r\t");

        process_one_mac(mac);

        sdsfree(mac);
        free(line);
    }
    else
    {
        printf("+---------input--------+----output----+-result-+\n");

        for(size_t i = 1; i < argc; ++i)
        {
            sds mac = sdsnew(argv[i]);
            process_one_mac(mac);
            sdsfree(mac);
        }
    }

    printf("+----------------------+--------------+--------+\n");

    return 0;
}
