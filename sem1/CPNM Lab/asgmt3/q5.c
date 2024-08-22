#include <stdio.h>

int main()
{
    int n, s = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        s += i * (i + 1);
    }

    printf("Sum: %d", s);
    return 0;
}