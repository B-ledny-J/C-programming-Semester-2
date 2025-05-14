/*
* @file Lab_4_1.c
* @author Дарчук Г.С., 515i
* @date 14.05.2025
* @brief Лабораторна робота №4, варіант 22
*
* Функції. Швидке сортування. Робота з відлагоджувачем. Завдання 1
*/

/* Швидке сортування */
#include <stdio.h>
#include <stdlib.h>

/* функція швидкого сортування */
void quicksort(int a[], int low, int high);

/* функція розділу масива */
int split(int a[], int low, int high);

void write_by_keyboard(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("Введіть %d елемент масиву для сортування:", i);
        scanf("%d", &arr[i]);
    }
}

void write_by_random(int arr[], int N, int range)
{
    // Для кращої читаності випадкові числа обмежені 300-ми числами
    for (int i = 0; i < N; i++) arr[i] = rand()%range;
}

void writeArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/* функція main */
int main()
{
    int length;
    int choice;
    int range;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &length);
    if (length <= 0)
    {
        printf("Помилка: массив не може бути меньшим або дорівнювати 0!\n");
        return 1;
    }
    int* a = (int*)malloc(length * sizeof(int));
    printf("Ввести елементи масиву з клавіатури (введіть 0) чи випадковим чином (введіть 1): ");
    scanf("%d", &choice);
    if (choice == 0) write_by_keyboard(a, length);
    else if (choice == 1)
    {
        printf("Введіть обмеження (максимальне випадкове число): ");
        scanf("%d", &range);
        write_by_random(a, length, range);
    }
    else
    {
        printf("Помилка: Введено інше число!\n");
        return 1;
    }
    printf("Вигляд масиву: ");
    writeArray(a, length);
    quicksort(a, 0, length - 1);
    printf("Вигляд відсортованного масиву: ");
    writeArray(a, length);
    return 0;
}

void quicksort(int a[], int low, int high)
{
  int middle;
  if (low >= high) return;
  middle = split(a, low, high);
  quicksort(a, low, middle - 1);
  quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high)
{
    int part_element = a[low];
    for(;;)
    {
        while (low < high && part_element >= a[high]) high--;
        if (low >= high) break;
        a[low++] = a[high];
        while (low < high && a[low] >= part_element) low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}