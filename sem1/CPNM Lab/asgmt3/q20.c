#include <stdio.h>

int main(void)
{
    int ps, sqrt = 0, i = 1, sum = 0;
    printf("Enter a  perfect square number: ");
    scanf("%d", &ps);

    while (sum < ps)
    {
        sum += i;
        i += 2, sqrt += 1;
    }

    printf("%d\n", sum);
    printf("The square root of %d is %d\n", ps, sqrt);
    return 0;
}