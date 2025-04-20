#include <stdio.h>
#include <stdlib.h>

void write_by_keyboard(int arr[][])
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

void write_by_random(int arr[][])
{
    for (int i = 0; i < 7; i++) for (int j = 0; j < 7; j++) arr[i][j] = rand()%151-75;
}

void writeArray(int arr[][])
{
    printf("Вигляд матриці:\n");
    // блок виведення елементів масиву, цикл прорахування рядків
    for (int i = 0; i < 7; i++)
    {
        // цикл прорахування стовпців
        for (int j = 0; j < 7; j++) printf("%d ", arr[i][j]);
        // перехід до наступної строки
        printf("\n");
    }
}

int sumOfSelected(int arr[][])
{
    int sum = 0;
    for (int i = 1; i < 7; i++) for (int j = 6; j > 6-i; j--) sum += arr[i][j];
    return sum;
}

int determinantFinder(int arr[][])
{
    int determinant = 0;
    determinant += arr[1][3] * (arr[2][4] * arr[3][5] - arr[2][5] * arr[3][4]);
    determinant -= arr[1][4] * (arr[2][3] * arr[3][5] - arr[2][5] * arr[3][3]);
    determinant += arr[1][5] * (arr[2][3] * arr[3][4] - arr[2][4] * arr[3][3]);
    return determinant;
}

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
    printf("Сума виділених елементів матриці: %d\n", sumOfSelected(matrix));
    printf("Визначник виділеної підматриці 3*3: %d\n", determinantFinder(matrix));
    return 0;
}