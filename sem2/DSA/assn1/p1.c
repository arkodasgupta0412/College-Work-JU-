#include <stdio.h>
#include <limits.h>

void factorialIterative(int n)
{
    int f = 1, flag = 0;
    long long fact;

    for (int i = 2; i <= n; i++)
    {
        if (i >= INT_MAX / f)
        {
            fact = f;
            flag = 1;
        }

        if (flag)
        {
            fact *= i;
        }
        else
        {
            f *= i;
        }
    }

    if (flag)
    {
        printf("Integer Overflow\n");
        printf("Factorial: %lld\n", fact);
    }
    else
    {
        printf("Factorial: %d\n", f);
    }
}

void factorialRecursive(int i, int flag, int n, long long fact, int f)
{
    if (i == n + 1)
    {
        if (flag)
        {
            printf("Integer overflow\n");
            printf("Factorial: %lld\n", fact);
        }
        else
        {
            printf("Factorial: %d\n", f);
        }
        return;
    }

    if (!flag)
    {
        if (i >= INT_MAX / f)
        {
            fact = f;
            flag = 1;
        }
    }

    if (flag)
    {
        fact *= i;
    }
    else
    {
        f *= i;
    }

    factorialRecursive(i + 1, flag, n, fact, f);
}

int main()
{
    int n1 = 9, n2 = 15;
    // iterative (without overflow)
    factorialIterative(n1);

    // iterative (with overflow)
    factorialIterative(n2);

    // recursive (without overflow)
    factorialRecursive(1, 0, n1, 1, 1);

    // recursive (with overflow)
    factorialRecursive(1, 0, n2, 1, 1);

    return 0;
}