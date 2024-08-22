#include <stdio.h>

int checkAmicable(int x, int y)
{
    int sx = 0, sy = 0;

    for (int i = 1; i <= x / 2; ++i)
    {
        if (x % i == 0)
        {
            sx += i;
        }
    }

    for (int j = 1; j <= y / 2; ++j)
    {
        if (y % j == 0)
        {
            sy += j;
        }
    }

    if (sx == y && sy == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n1, n2;
    printf("Enter n1 and n2: ");
    scanf("%d %d", &n1, &n2);

    int res = checkAmicable(n1, n2);

    if (res)
    {
        printf("%d\n", res);
    }
    else
    {
        printf("%d\n", res);
    }
    return 0;
}