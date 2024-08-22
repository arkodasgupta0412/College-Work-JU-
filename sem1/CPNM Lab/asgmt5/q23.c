#include <stdio.h>

int main()
{
    int n, sum = 0;
    printf("Enter number of numbers you want to enter: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray Traversal:\n");

    for (int i = 0; i < n; ++i)
    {
        printf("arr[%d] = %d\n", i, *(arr + i));
        sum += *(arr + i);
    }

    printf("\n");

    printf("Sum = %d", sum);
    return 0;
}