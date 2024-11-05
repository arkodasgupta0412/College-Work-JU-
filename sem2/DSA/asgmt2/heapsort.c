#include <stdio.h>
#include "maxHeap.c"
#include "minHeap.c"
#include "utils.h"

void heapSort(int arr[], int n, int *cmp)
{
    build_max_heap(arr, n, cmp);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0, cmp);
    }
}

/* int main()
{
    int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    heapSort(arr, size, &count);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
} */