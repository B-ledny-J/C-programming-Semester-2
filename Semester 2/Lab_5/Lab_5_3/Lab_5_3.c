/*
* @file Lab_5_1.c
* @author Дарчук Г.С., 515i
* @date 22.05.2025
* @brief Лабораторна робота №5, варіант 22
*
* Функції. Застосування вказівників. Завдання 3
*/

#include <stdio.h>
#include <stdlib.h>

int matrix_spiral(int* matrix, int n, int num)
{
    int *matPtr = matrix, top = 0, left = 0, bottom = n - 1, right = n - 1;
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) *(matrix + top * n + i) = num++;
        top++;
        for (int i = top; i <= bottom; ++i) *(matrix + i * n + right) = num++;
        right--;
        if (top <= bottom) {
            for (int i = right; i >= left; --i) *(matrix + bottom * n + i) = num++;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; --i) *(matrix + i * n + left) = num++;
            left++;
        }
    }
}

void print_matrix(int* matrix, int n)
{
    printf("Вигляд матриці:\n");
    for (int i = 0; i < n; i++)
    {
        int *rowStart = matrix + i * n;
        for (int j = 0; j < n; j++) printf("%3d ", *(rowStart + j));
        printf("\n");
    }
}

int main()
{
    int rowsColumns, firstNum;
    printf("Введіть розмірність квадратної матриці: ");
    scanf("%d", &rowsColumns);
    if (rowsColumns < 1)
    {
        printf("Помилка: розмірність матриці не може бути меншою за 1\n");
        return 1;
    }
    int** arr = (int**)calloc(rowsColumns, sizeof(int*));
    for (int i = 0; i < rowsColumns; i++) arr[i] = (int*)calloc(rowsColumns, sizeof(int));
    printf("Введіть перше число матриці: ");
    scanf("%d", &firstNum);
    matrix_spiral(arr, rowsColumns, firstNum);
    print_matrix(arr, rowsColumns);
    return 0;
}