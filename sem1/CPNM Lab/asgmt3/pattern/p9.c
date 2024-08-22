/* n = 4
      +
     + +
    +   +
   +     +
    +   +
     + +
      +
*/

#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int totalRows = n * 2 - 1;
    int i, j;

    for (i = 1; i <= totalRows; i++)
    {
        for (j = 1; j <= totalRows; j++)
        {
            if (i <= n)
            {
                if (j == n - i + 1 || j == n + i - 1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            else
            {
                if (j == i - n + 1 || j == totalRows - i + n)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    return 0;
}
