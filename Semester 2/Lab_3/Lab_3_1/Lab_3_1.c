#include <stdio.h>

int check_repeated_digits(long n);

int count_repeated_digits(long n, int counted[])
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

int main()
{
    long n;
    int digit_seen_counted[10] = {0};
    printf("Введіть число: ");
    scanf("%ld", &n);
    if (check_repeated_digits(n))
    {
        printf("Є цифри, що повторюються:\n");
        count_repeated_digits(n, digit_seen_counted);
        write_repeated_digits(digit_seen_counted);
    }
    else
        printf("Немає цифр, що повторюються\n");
    return 0;
}

int check_repeated_digits(long n){
    int digit_seen[10] = {0};
    int digit;
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) /* Якщо така цифра вже є */
            break; /* то це означає, що є цифри, що повторюються */
        digit_seen[digit] = 1;
        n /= 10;
    }
    return n;
}