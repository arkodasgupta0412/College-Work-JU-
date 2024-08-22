// C program to print kaprekar number. Note that 10, 100, 1000... are not Kaprekar numbers

#include <stdio.h>
#include <math.h>

int countDigits(int x)
{
    int c = 0;
    while (x)
    {
        c += 1;
        x /= 10;
    }

    return c;
}

int getTenthPow(int x)
{
    int p = 1;
    while (x--)
    {
        p *= 10;
    }
    return p;
}

int isKaprekar(int x)
{
    int sq = x * x, digitsOfSq = countDigits(sq);

    // printf("square = %d\n", sq);

    if (x == 1)
    {
        return 1;
    }

    for (int i = 1; i < digitsOfSq; ++i)
    {
        int part1 = sq / getTenthPow(i);
        int part2 = sq % getTenthPow(i);

        // printf("part1 = %d,     part2 = %d\n", part1, part2);
        // printf("sum = %d\n", part1 + part2);

        if (part1 > 0 && part2 > 0 && part1 + part2 == x)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    // int n;
    // printf("Enter the value of n: ");
    // scanf("%d", &n);

    // if (isKaprekar(n))
    // {
    //     printf("%d is a Kaprekar number\n", n);
    // }
    // else
    // {
    //     printf("%d is not a Kaprekar number\n", n);
    // }

    for (int i = 1; i <= 10000; ++i)
        if (isKaprekar(i))
            printf("%d ", i);

    return 0;
}