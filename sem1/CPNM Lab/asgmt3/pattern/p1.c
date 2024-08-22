/*  1
    1 2
    1 2 3
    1 2 3 4
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int row = 1; row <= n; ++row)
    {
        for (int col = 1; col <= row; ++col)
        {
            printf("%d ", col);
        }

        printf("\n");
    }
    return 0;
}