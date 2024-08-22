#include <stdio.h>

int main()
{
    int n;

    // Input the value of n from the user
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Print integers divisible by n between 1 and 100
    printf("Integers divisible by %d between 1 and 100:\n", n);

    for (int i = 1; i <= 100; i++)
    {
        if (i % n == 0)
        {
            printf("%d, ", i);
        }
    }

    return 0;
}
