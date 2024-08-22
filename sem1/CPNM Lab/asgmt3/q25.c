#include <stdio.h>

float factorial(int x)
{
    int i = 1, f = 1.0;
    while (i <= x)
    {
        f *= i;
        ++i;
    }

    return f;
}

int main(void)
{
    float sum = 0;
    for (int i = 1; i <= 7; ++i)
    {
        sum += (i / factorial(i));
    }

    printf("The sum of 1/1! + 2/2! + ... + 7/7! is:   \n%.3f\n", sum);
    return 0;
}