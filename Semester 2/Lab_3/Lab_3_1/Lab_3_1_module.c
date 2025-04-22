#include <stdio.h>
#include "Lab_3_1_module.h"

void count_repeated_digits(long n, int counted[])
{
    int digit;
    if (n < 0) n *= -1;
    while (n > 0) {
        digit = n % 10;
        counted[digit] += 1;
        n /= 10;
    }
}

void write_repeated_digits(int arr[])
{
    for (long i = 0; i < 10; i++)
    {
        if (arr[i] > 1) printf("%d (%d разів)\n", i, arr[i]);
    }
}