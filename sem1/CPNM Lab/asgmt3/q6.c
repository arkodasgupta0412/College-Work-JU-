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
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial of negative number does not exist\n");
    }
    else
    {
        printf("Factorial of %d is %d\n", n, factorial(n));
    }
    return 0;
}