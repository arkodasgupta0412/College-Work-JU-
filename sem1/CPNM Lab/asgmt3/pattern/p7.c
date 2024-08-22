/*
    1
   121
  12321
 1234321
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
        int col;
        for (int k = 0; k < space; ++k)
        {
            printf(" ");
        }

        for (col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        if (row != 1)
        {
            // why col1 = col - 2
            // because for the previous loop, suppose in row3, col = 4 after previous loop termination
            // so I need to decrement col by 2 (4 - 2 = 2) to start printing col again from 2->1
            for (int col1 = col - 2; col1 >= 1; --col1)
            {
                printf("%d ", col1);
            }
        }

        space -= 2;
        printf("\n");
    }
    return 0;
}