#include <stdio.h>

int main(void)
{
    int first = 0, second = 1, n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("%d, %d", first, second);

    while (n > 2)
    {
        int third = first + second;
        printf(", %d", third);
        first = second;
        second = third;
        --n;
    }
    return 0;
}