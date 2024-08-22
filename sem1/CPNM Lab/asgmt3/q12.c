#include <stdio.h>

int main()
{
    int n;
    printf("Enter number whose table is to be printed: ");
    scanf("%d", &n);

    printf("MULTIPLICATION TABLE OF %d:\n", n);
    for (int i = 1; i <= 10; ++i)
    {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}