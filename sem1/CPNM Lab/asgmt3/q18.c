#include <stdio.h>

int checkArmstrong(int x)
{
    int x1 = x, sum = 0;
    while (x > 0)
    {
        sum += (x % 10) * (x % 10) * (x % 10);
        x /= 10;
    }

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
    printf("The armstrong numbers between 1 and 500 are: ");
    for (int i = 1; i <= 500; ++i)
    {
        if (checkArmstrong(i))
        {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}