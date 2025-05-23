/*
* @file Lab_4_3.c
* @author Дарчук Г.С., 515i
* @date 14.05.2025
* @brief Лабораторна робота №4, варіант 22
*
* Функції. Швидке сортування. Робота з відлагоджувачем. Завдання 3
*/

#include <stdio.h>
#include <math.h>

// Ця функція перевіряє число на автоморфність. Вона приймає ціле число на вході та повертає 0, якщо число не є автоморфним, та 1, якщо число дійсно є автоморфним
int is_automorphic(int num);

// Ця функція шукає найближче автоморфне число до поданого. Вона приймає ціле число на вході та повертає найближче до нього автоморфне число, але не самого себе
int near_automorphic(int num);

int main()
{
    unsigned int num;
    printf("Введіть число для перевірки на автоморфність: ");
    scanf("%d", &num);
    int result = is_automorphic(num);
    if (result == 1) printf("Число є автоморфним\n");
    else
    {
        printf("Число не є автоморфним\n");
        int near_result = near_automorphic(num);
        printf("Найближче до нього автоморфне число: %d", near_result);
    }
    return 0;
}

int is_automorphic(int num)
{
    int count = 0;
    for (int temp_num = num; temp_num != 0; temp_num /= 10) count++;
    int squared = pow(num, 2);
    int mod = pow(10, count);
    return (squared % mod == num);
}

int near_automorphic(int num)
{
    int less = num-1;
    int greater = num+1;
    for (int i = 0;; i++)
    {
        if (is_automorphic(less)) return less;
        else if (is_automorphic(greater)) return greater;
        less -= 1;
        greater += 1;
    }
}