#include <stdio.h>

int sumFactors(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        // checking for factor
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

int main()
{
    int n, s = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        s += sumFactors(i);
    }

    printf("Sum: %d\n", s);

    return 0;
}