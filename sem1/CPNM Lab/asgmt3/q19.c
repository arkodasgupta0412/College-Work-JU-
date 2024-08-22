// check happy number

#include <stdio.h>

int sumSquaresDigits(int x)
{
    int s = 0;
    while (x > 0)
    {
        s += (x % 10) * (x % 10);
        x /= 10;
    }

    return s;
}

int checkHappy(int x)
{
    int iterations = 100;

    while (iterations > 0)
    {
        x = sumSquaresDigits(x);

        if (x == 1)
        {
            return 1; // Happy number
        }

        iterations--;
    }

    return 0; // Not a happy number within 100 iterations
}

int main(void)
{
    int n;
    printf("Enter number: ");
    scanf("%d", &n);

    if (checkHappy(n))
    {
        printf("%d is a happy number", n);
    }
    else
    {
        printf("%d is not a happy number", n);
    }
}