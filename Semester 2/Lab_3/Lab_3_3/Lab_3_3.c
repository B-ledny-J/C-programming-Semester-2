/*
* @file Lab_3_3.c
* @author Дарчук Г.С., 515i
* @date 24.02.2025
* @brief Лабораторна робота №3, варіант 22
*
* Використання масивів. Завдання 3
*/

#include <stdio.h>

#include "Lab_3_3_module.h"

int main()
{
    int matrix[7][7];
    int choice;
    printf("Ввести елементи масиву з клавіатури (введіть 0) чи випадковим чином (введіть 1): ");
    scanf("%d", &choice);
    if (choice == 0) write_by_keyboard(matrix);
    else if (choice == 1) write_by_random(matrix);
    else
    {
        printf("Помилка: Введено інше число!\n");
        return 1;
    }
    writeArray(matrix);
    writeData(sumOfSelected(matrix), determinantFinder(matrix));
    return 0;
}