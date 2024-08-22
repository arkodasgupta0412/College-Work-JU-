/*
    +
   +++
  +++++
 +++++++
  +++++
   +++
    +
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int space = n - 1, plus = 1;

    for (int row = 1; row <= 2 * n - 1; ++row)
    {

        if (row <= n)
        {
            // printf("row = %d and space = %d and plus = %d\n", row, space, plus);
            for (int i = 0; i < space; ++i)
            {
                printf(" ");
            }

            for (int i = 0; i < plus; ++i)
            {
                printf("+");
            }

            space -= 1, plus += 2;
        }

        else
        {
            if (space == -1 && plus == 2 * n + 1)
            {
                space = 1, plus -= 4;
            }

            for (int i = 0; i < space; ++i)
            {
                printf(" ");
            }

            for (int i = 0; i < plus; ++i)
            {
                printf("+");
            }

            space += 1, plus -= 2;
        }

        printf("\n");
    }
    return 0;
}