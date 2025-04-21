#include <stdio.h>
#include <stdlib.h>

void write_by_keyboard(int arr[7][7])
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("Введіть елемент %d рядка %d стовпця масиву:", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void write_by_random(int arr[7][7])
{
    for (int i = 0; i < 7; i++) for (int j = 0; j < 7; j++) arr[i][j] = rand()%151-75;
}

void writeArray(int arr[7][7])
{
    printf("Вигляд матриці:\n");
    // блок виведення елементів масиву, цикл прорахування рядків
    for (int i = 0; i < 7; i++)
    {
        // цикл прорахування стовпців
        for (int j = 0; j < 7; j++) printf("%3d ", arr[i][j]);
        // перехід до наступної строки
        printf("\n");
    }
}

int sumOfSelected(int arr[7][7])
{
    int sum = 0;
    for (int i = 1; i < 7; i++) for (int j = 6; j > 6-i; j--) sum += arr[i][j];
    return sum;
}

int determinantFinder(int arr[7][7])
{
    int determinant = 0;
    determinant += arr[1][3] * (arr[2][4] * arr[3][5] - arr[2][5] * arr[3][4]);
    determinant -= arr[1][4] * (arr[2][3] * arr[3][5] - arr[2][5] * arr[3][3]);
    determinant += arr[1][5] * (arr[2][3] * arr[3][4] - arr[2][4] * arr[3][3]);
    return determinant;
}