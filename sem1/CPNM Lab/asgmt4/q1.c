#include <stdio.h>

void print_array(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
}

void reverse_array(int a[], int n)
{
    int rev[n];
    for (int i = 0; i < n; ++i)
    {
        rev[i] = a[n - i - 1];
    }

    printf("Reversed array: ");
    print_array(rev, n);
}

int main()
{
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    // input array
    printf("Enter %d array elements:\n", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array entered: ");
    print_array(arr, n);

    printf("\n");
    reverse_array(arr, n);

    return 0;
}