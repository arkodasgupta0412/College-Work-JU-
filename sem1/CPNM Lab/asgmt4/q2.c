#include <stdio.h>

int main()
{
    int n, dup = 0;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n], unique[n], c = 0;

    printf("Enter %d array elements: ", n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        int is_unique = 1;
        for (int j = 0; j < c; ++j)
        {
            if (arr[i] == unique[j])
            {
                dup += 1;
                is_unique = 0;
            }
        }
        if (is_unique)
        {
            unique[c++] = arr[i];
        }
    }

    printf("Number of duplicate elements: %d\n", dup);

    // printing unique element array
    printf("Unique array: ");
    for (int i = 0; i < c; ++i)
    {
        printf("%d ", unique[i]);
    }
    return 0;
}