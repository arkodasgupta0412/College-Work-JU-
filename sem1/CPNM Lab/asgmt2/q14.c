#include <stdio.h>

int powerTen(int x)
{
    int p = 1;
    while (x > 1)
    {
        p *= 10;
        x--;
    }
    return p;
}

int main()
{
    int num, newnum = 0, i = 5;
    printf("Enter 5-digit integer: ");
    scanf("%d", &num);

    while (i)
    {
        int digit = num / powerTen(i);

        if (digit == 9)
        {
            newnum = newnum * 10 + 0;
        }
        else
        {
            newnum = newnum * 10 + (num / powerTen(i) + 1);
        }

        num = num % powerTen(i);
        i--;
    }

    printf("new number: %d\n", newnum);

    return 0;
}