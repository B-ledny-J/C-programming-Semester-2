#include <stdio.h>

int digit_seen_counted[10] = {0};

int check_repeated_digits(long n);

int count_repeated_digits(long n)
{
    int digit;
    while (n > 0) {
        digit = n % 10;
        digit_seen_counted[digit] += 1;
        n /= 10;
    }
    return n;
}

void write_repeated_digits()
{
    for (long i = 0; i < 10; i++)
    {
        if (digit_seen_counted[i] > 1) printf("%d (%d разів)\n", i, digit_seen_counted[i]);
    }
}

int main()
{
    long n;
    printf("Введіть число: ");
    scanf("%ld", &n);
    if (check_repeated_digits(n))
    {
        count_repeated_digits(n);
        printf("Є цифри, що повторюються:\n");
        write_repeated_digits();
    }
    else
        printf("Немає цифр, що повторюються\n");
    return 0;
}

int check_repeated_digits(long n)
{
    int digit_seen[10] = {0};
    int digit;
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            break;
        digit_seen[digit] = 1;
        n /= 10;
    }
    return n;
}