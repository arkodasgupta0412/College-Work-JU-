#include <stdio.h>

int main(void)
{
    int n, ops = 0;
    printf("Enter initial value: ");
    scanf("%d", &n);

    printf("Initial value is %d\n\n", n);
    while (n != 1)
    {
        if (n % 2 == 0)
        {
            n = n / 2;
        }

        else
        {
            n = 3 * n + 1;
        }

        printf("Next value is %d\n\n", n);
        ops += 1;
    }

    printf("Next value is %d\n\n", n);

    printf("Number of operations is %d\n", ops);
}