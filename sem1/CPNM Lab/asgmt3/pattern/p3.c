/*
      1
    1 2 1
  1 2 3 2 1
1 2 3 4 3 2 1
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int space = 2 * (n - 1);

    for (int row = 1; row <= n; ++row)
    {
        for (int k = 0; k < space; ++k)
        {
            printf(" ");
        }

        for (int col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        for (int col = row - 1; col >= 1; --col)
        {
            printf("%d ", col);
        }

        space -= 2;
        printf("\n");
    }
    return 0;
}