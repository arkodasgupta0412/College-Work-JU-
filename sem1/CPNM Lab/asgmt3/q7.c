#include <stdio.h>

int factorial(int n)
{
    int f = 1, i = 1;
    while (i <= n)
    {
        f *= i;
        i++;
    }
    return f;
}

int main()
{
    int n, s = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        s += factorial(i);
    }

    printf("Sum: %d\n", s);

    return 0;
}