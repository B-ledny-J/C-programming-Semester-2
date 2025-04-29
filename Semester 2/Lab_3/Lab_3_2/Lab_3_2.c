/*
* @file Lab_3_1.c
* @author Дарчук Г.С., 515i
* @date 24.04.2025
* @brief Лабораторна робота №3, варіант 22
*
* Використання масивів. Завдання 2
*/


#include <stdio.h>
#include <stdlib.h>

void write_by_keyboard(int arr[], unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Введіть %d-й елемент масиву:", i);
        scanf("%d", &arr[i]);
    }
}

void write_by_random(int arr[], unsigned int size)
{
    for (int i = 0; i < size; i++) arr[i] = rand();
}

int minimalNumberIndexFind(int arr[], unsigned int size)
{
    int min = arr[0];
    int minIndex = 0;
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
        {
            min = arr[i];
            minIndex = i;
        }
    return minIndex;
}

int oddSumBeforeMinimal(int arr[], int min)
{
    int sum = 0;
    for (int i  = 1; i < min; i += 2) sum += arr[i];
    return sum;
}

void writeMinimalNumIndex(int arr[], int minIndex)
{
    printf("Мінімальне число массиву: %d\n", arr[minIndex]);
    printf("Індекс мінімального числа масиву: %d\n", minIndex);
}

void writeArray(int arr[], unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    unsigned int N;
    int choice;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);
    if (N > 100)
    {
        printf("Помилка: кількість елементів масиву не може бути більшим за 100\n");
        return 1;
    }
    int* numberArr = (int*)malloc(N * sizeof(int));
    printf("Ввести елементи масиву з клавіатури (введіть 0) чи випадковим чином (введіть 1): ");
    scanf("%d", &choice);
    if (choice == 0) write_by_keyboard(numberArr, N);
    else if (choice == 1) write_by_random(numberArr, N);
    else
    {
        printf("Помилка: Введено інше число!\n");
        return 1;
    }
    printf("Вигляд введеноного масива: ");
    writeArray(numberArr, N);
    int minimalNumberIndex = minimalNumberIndexFind(numberArr, N);
    writeMinimalNumIndex(numberArr, minimalNumberIndex);
    if (minimalNumberIndex == 0 || minimalNumberIndex == 1)
    {
        printf("Перше або число є мінімальним! Розрахунок неможливий!\n");
        return 1;
    }
    else printf("Сума елементів масиву с непарними індексами, що знаходяться до мінімального елемента: %d\n", oddSumBeforeMinimal(numberArr, minimalNumberIndex));
    return 0;
}