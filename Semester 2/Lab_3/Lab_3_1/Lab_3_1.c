/*
* @file Lab_3_1.c
* @author Дарчук Г.С., 515i
* @date 24.04.2025
* @brief Лабораторна робота №3, варіант 22
*
* Використання масивів. Завдання 1
*/

#include <stdio.h>
#include "Lab_3_1_module.h"

int check_repeated_digits(long n);

int main()
{
    long n;
    int digit_seen_counted[10] = {0};
    printf("Введіть число: ");
    scanf("%ld", &n);
    if (check_repeated_digits(n) != 0)
    {
        printf("Є цифри, що повторюються:\n");
        count_repeated_digits(n, digit_seen_counted);
        write_repeated_digits(digit_seen_counted);
    }
    else
        printf("Немає цифр, що повторюються\n");
    return 0;
}

int check_repeated_digits(long n){
    int digit_seen[10] = {0};
    int digit;
    if (n < 0) n *= -1;
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) /* Якщо така цифра вже є */
            break; /* то це означає, що є цифри, що повторюються */
        digit_seen[digit] = 1;
        n /= 10;
    }
    return n;
}