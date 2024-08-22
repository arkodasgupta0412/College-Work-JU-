#include <stdio.h>
#include <math.h>

float mean(int a[], int n)
{
    float s = 0.0;
    for (int i = 0; i < n; ++i)
    {
        s += a[i];
    }

    return s / n;
}

float stdDev(int a[], int n, float mean)
{
    float s1 = 0.0;
    for (int i = 0; i < n; ++i)
    {
        s1 += pow(a[i] - mean, 2);
    }

    return sqrt(s1 / n);
}

void print_array(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter array elements: ");
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }

    printf("Array entered: ");
    print_array(arr, size);

    printf("Standard deviation: %.3f\n", stdDev(arr, size, mean(arr, size)));
    return 0;
}