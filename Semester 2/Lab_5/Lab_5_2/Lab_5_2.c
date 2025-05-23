/*
* @file Lab_5_1.c
* @author Дарчук Г.С., 515i
* @date 22.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Функції. Застосування вказівників. Завдання 2
*/

#include <stdio.h>
#include <stdlib.h>

void arrayInput(int* arrFirst, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Введить %d елемент масиву: ", i);
        scanf("%d", (arrFirst + i));
    }
}

void arrayCount(int* arrFirst, int size, int* counter)
{
    int* arrPtr = arrFirst;
    int *counterStart = counter;
    for (int i = 0; i < size; i++, arrPtr++)
    {
        switch (*arrPtr)
        {
            case 0:
            case 1:
            case 2:
                (*counter)++;
                break;
            case 3:
                counter += 1;
                (*counter)++;
                break;
            case 4:
                counter += 2;
                (*counter)++;
                break;
            case 5:
                counter += 3;
                (*counter)++;
                break;
            default:
                counter += 4;
                (*counter)++;
                break;
        }
        counter = counterStart;
    }
}

void arrayPrint(int *a, int size)
{
    printf("Кіькість змінних, що знаходяться в діапазоні від 0 до 2: %d\n", *a);
    for (int i = 1; i < (size-1); i++)
    {
        printf("Кількість змінних, що дорівнюють %d: %d\n", (i+2), *(a+i));
    }
    printf("Кількість символів, що не увійшли в діапазон: %d\n", *(a+size-1));
}

int main()
{
    int size, arrCount[5] = {0};
    printf("Введіть кількість цифр: ");
    scanf("%d", &size);
    if (size < 1)
    {
        printf("Помилка: кількість цифр не може бути меншою за 1\n");
        return 1;
    }
    int* arr = (int*)calloc(size, sizeof(int));
    arrayInput(arr, size);
    arrayCount(arr, size, arrCount);
    arrayPrint(arrCount, 5);
    return 0;
}
