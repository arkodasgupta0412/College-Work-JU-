/*
   +++++++++
   ++++ ++++
   +++   +++
   ++     ++
   +       +
   ++     ++
   +++   +++
   ++++ ++++
   +++++++++

 */

#include <stdio.h>

int main()
{
    int n, midspace = 1;

    printf("Enter n: ");
    scanf("%d", &n);

    // topmost row with no midspace
    for (int col = 0; col < 2 * n + 1; ++col)
    {
        printf("*");
    }
    printf("\n");

    // top half
    for (int row = 0; row < n; ++row)
    {
        for (int col = n - row; col >= 1; --col)
        {
            printf("*");
        }
        for (int col = 0; col < midspace; ++col)
        {
            printf(" ");
        }
        for (int col = n - row; col >= 1; --col)
        {
            printf("*");
        }
        midspace += 2;
        printf("\n");
    }

    // bottomhalf
    midspace -= 4;
    int j = 0;

    for (int row = n; row < 2 * n - 1; ++row)
    {
        for (int col = 0; col < 2 + j; ++col)
        {
            printf("*");
        }

        for (int col = 0; col < midspace; ++col)
        {
            printf(" ");
        }

        for (int col = 0; col < 2 + j; ++col)
        {
            printf("*");
        }

        j += 1;
        midspace -= 2;
        printf("\n");
    }

    // bottommost row with no spaces
    for (int col = 0; col < 2 * n + 1; ++col)
    {
        printf("*");
    }
    printf("\n");
    return 0;
}
