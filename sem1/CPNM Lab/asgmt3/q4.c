#include <stdio.h>

int main()
{
    int n, s = 0;
    printf("Enter n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
    {
        s += i;
    }

    printf("Sum: %d", s);
    return 0;
}