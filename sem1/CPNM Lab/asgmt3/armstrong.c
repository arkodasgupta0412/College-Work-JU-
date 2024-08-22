#include <stdio.h>
#include <math.h>

int countDigits(int x)
{
    int c = 0;
    while (x > 0)
    {
        c += 1;
        x /= 10;
    }

    return c;
}

// n -> count of digits in the number
int isArmstrong(int x, int n)
{
    int x1 = x, sum = 0;
    while (x > 0)
    {
        int digit = x % 10, multiplier = 1;
        ;
        for (int i = 1; i <= n; ++i)
        {
            multiplier *= digit;
        }
        sum += multiplier;
        x /= 10;
    }

    printf("sum: %d\n", sum);

    if (sum == x1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    printf("%d\n", countDigits(n));
    if (isArmstrong(n, countDigits(n)))
    {
        printf("%d is an Armstrong number", n);
    }

    else
    {
        printf("%d is not an Armstrong number", n);
    }

    return 0;
}