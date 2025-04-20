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
    int sum = arr[0];
    for (int i  = 2; i < min; i += 2) sum += arr[i];
    return sum;
}

void temp_writeDown(int arr[], unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
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
    temp_writeDown(numberArr, N);
    int minimalNumberIndex = minimalNumberIndexFind(numberArr, N);
    printf("%d", minimalNumberIndex);
    if (minimalNumberIndex == 0)
    {
        printf("Перше число є мінімальним! Розрахунок неможливий!\n");
        return 1;
    }
    else printf("Сума елементів масиву с непарними індексами, що знаходяться до мінімального елемента: %d\n", oddSumBeforeMinimal(numberArr, minimalNumberIndex));
    return 0;
}