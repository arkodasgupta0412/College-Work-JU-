#include <stdio.h>

int countLength(int n)
{
    int c = 0;
    while (n)
    {
        c += 1, n /= 10;
    }
    return c;
}

int powerTen(int x)
{
    int p = 1;
    while (x >= 1)
    {
        p *= 10;
        x--;
    }
    return p;
}

int main()
{
    int X, Y;
    printf("Enter two numbers:\n");
    printf("X = ");
    scanf("%d", &X);
    printf("Y = ");
    scanf("%d", &Y);

    // We form Z by concatenating X and Y
    // example: X = 12, Y = 345, then Z = 12345

    int Z = (X * powerTen(countLength(Y))) + Y;

    printf("X = %d, Y = %d\n", X, Y);
    printf("Z = %d\n", Z);

    return 0;
}