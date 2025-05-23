/*
* @file Lab_5_1_module.c
* @author Дарчук Г.С., 515i
* @date 19.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Функції. Застосування вказівників. Завдання 1
*/

int lamp_info_writeDown(int mark, int *colorIndex, int *temperature)
{
    if (mark < 100 || mark > 999 || (mark%100) == 0) return 0;
    *colorIndex = mark/100*10;
    *temperature = (mark%100)*100;
    return 1;
}