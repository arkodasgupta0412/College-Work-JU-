/* n = 4
    4 3 2 1 0
    3 2 1
    2
*/

#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int k = n;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (int j = k; j >= i - 1; --j)
        {
            printf("%d ", j);
        }
        printf("\n");
        --k;
    }
    return 0;
}