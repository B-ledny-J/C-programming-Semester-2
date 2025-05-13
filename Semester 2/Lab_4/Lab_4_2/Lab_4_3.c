#include <stdio.h>

// !! check pdf-file !!
int is_automorphic(int num);

// !! check pdf-file !!
int near_automorphic(int num);

int main()
{
    int num;
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