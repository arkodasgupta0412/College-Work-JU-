#include <stdio.h>

int main()
{
    int a, b, l, s;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    if (a > b)
        l = a, s = b;

    else
        l = b, s = a;

    printf("Fractional form: %d/%d\n", l, s);
    printf("Decimal form: %.1f\n", (float)l / s);

    return 0;
}