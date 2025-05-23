/*
* @file Lab_5_1.c
* @author Дарчук Г.С., 515i
* @date 19.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Функції. Застосування вказівників. Завдання 1
*/

#include <stdio.h>
#include "Lab_5_1_module.h"

int main()
{
    int lamp_mark;
    int lamp_CRI; // індекс кольоропередачі
    int lamp_temperature;
    printf("Введіть маркування лампи: ");
    scanf("%d", &lamp_mark);
    int status = lamp_info_writeDown(lamp_mark, &lamp_CRI, &lamp_temperature);
    if (status == 0) printf("Помилка: перетворення неуспішне!\nЧисло є від'ємним, не трьохзначним або кратно 100\n");
    else
    {
        printf("Перетворення успішне!\n");
        printf("Маркування лампи: %d\nІндекс кольоропередачі: %d\nКольорова температура: %d\n", lamp_mark, lamp_CRI, lamp_temperature);
    }
    return 0;
}