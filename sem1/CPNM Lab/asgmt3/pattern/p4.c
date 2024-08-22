/*      1
       1 1
      1 2 1
     1 2 2 1
    1 2 3 2 1
   1 2 3 3 2 1
  1 2 3 4 3 2 1
 1 2 3 4 4 3 2 1
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int space = 2 * n - 2;

    for (int i = 1; i <= 2 * n - 1; ++i)
    {
        // printing the spaces
        for (int m = 0; m < space; ++m)
        {
            printf(" ");
        }

        // printing the numbers
        if (i % 2 != 0)
        {
            int j;

            if (i == 1)
            {
                printf("1");
            }
            else
            {
                for (j = 1; j < i; ++j)
                {
                    if (j > (i / 2) + 1)
                    {
                        break;
                    }
                    printf("%d ", j);
                }

                for (int k = j - 2; k >= 1; --k)
                {
                    printf("%d ", k);
                }
            }
        }

        else
        {
            int j;
            if (i == 2)
            {
                printf("1 1");
            }
            else
            {
                for (j = 1; j < 2 * i; ++j)
                {
                    if (j > i / 2)
                    {
                        break;
                    }
                    printf("%d ", j);
                }

                // printf("j = %d", j);

                for (int k = j - 1; k >= 1; --k)
                {
                    printf("%d ", k);
                }
            }
        }
        printf("\n");
        space -= 1;
    }
}