#include <stdio.h>

int main()
{
    int i, p = 0, n = 0, z = 0;
    printf("Enter 10 integers one by one:\n");

    for (int j = 0; j < 10; ++j)
    {
        scanf("%d", &i);
        if (i > 0)
        {
            p += 1;
        }
        else if (i == 0)
        {
            z += 1;
        }
        else
        {
            n += 1;
        }
    }

    printf("\nNumber of positive integers: %d\n", p);
    printf("Number of zeroes: %d\n", z);
    printf("Number of negative integers: %d\n", n);

    return 0;
}