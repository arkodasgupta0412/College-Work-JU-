#include <stdio.h>

int octal(int n)
{
    int oct = 0;

    if (n == 0)
    {
        return oct;
    }
    else
    {
        oct = (n % 8) + (10 * octal(n / 8));
    }
}

int main()
{
    int decimal;
    printf("Enter the decimal: ");
    scanf("%d", &decimal);

    int oct = octal(decimal);

    printf("Octal: %d\n", oct);
    return 0;
}