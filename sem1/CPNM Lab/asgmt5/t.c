#include <stdio.h>

void pattern(int n)
{
    int space = 2 * n - 2;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < space; ++j)
        {
            printf(" ");
        }

        for (int j = 1; j <= i + 1; ++j)
        {
            printf("%d ", j);
        }

        printf("\n");
        space -= 2;
    }
}

int main()
{
    pattern(6);
    return 0;
}