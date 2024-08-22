#include <stdio.h>

int main()
{
    int n, s = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    int n1 = n;

    if (n < 0)
        n = -n;

    while (n)
    {
        s += (n % 10);
        n /= 10;
    }

    printf("The sum of digits of %d is %d\n", n1, s);

    return 0;
}