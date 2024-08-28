#include <stdio.h>
#include <limits.h>

void fibonacciIterative(int n)
{
    if (n <= 0)
    {
        printf("Invalid input\n");
        return;
    }
    if (n == 1 || n == 2)
    {
        printf("%dth fibonacci number: %d\n", n - 1);
        return;
    }

    int first = 0, second = 1, third;
    long long int First, Second, Third;
    int flag = 0;

    for (int i = 2; i < n; i++)
    {
        if (!flag)
        {
            if (first > INT_MAX - second)
            {

                First = first;
                Second = second;
                flag = 1;
            }
            else
            {
                third = first + second;
                first = second;
                second = third;
            }
        }

        if (flag)
        {
            Third = First + Second;
            First = Second;
            Second = Third;
        }
    }

    if (flag)
    {
        printf("Integer Overflow\n");
        printf("%dth fibonacci number: %lld\n", n, Third);
    }
    else
    {
        printf("%dth fibonacci number: %d\n", n, third);
    }
}

void fibonacciRecursive(int i, int flag, int n)
{
    int first = 0, second = 1, third;
    long long int First, Second, Third;

    if (n <= 0)
    {
        printf("Invalid input\n");
        return;
    }
    if (n == 1 || n == 2)
    {
        printf("%dth fibonacci number: %d\n", n - 1);
        return;
    }

    if (i == n)
    {
        if (flag)
        {
            printf("Integer Overflow\n");
            printf("%dth fibonacci number: %lld\n", n, Third);
        }
        else
        {
            printf("%dth fibonacci number: %d\n", n, third);
        }
        return;
    }

    if (!flag)
    {
        if (first > INT_MAX - second)
        {

            First = first;
            Second = second;
            flag = 1;
        }
        else
        {
            third = first + second;
            first = second;
            second = third;
        }
    }

    if (flag)
    {
        Third = First + Second;
        First = Second;
        Second = Third;
    }

    fibonacciRecursive(i + 1, 0, n);
}

int main()
{
    int n = 93;
    fibonacciRecursive(2, 0, n);
    return 0;
}