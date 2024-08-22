#include <stdio.h>

int main()
{
    float a, b;
    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    printf("Numbers before swapping: a = %.2f, b = %.2f\n", a, b);

    float tmp = a;
    a = b, b = tmp;
    printf("Numbers after swapping: a = %.2f, b = %.2f\n", a, b);

    return 0;
}