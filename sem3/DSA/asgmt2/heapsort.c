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

int main()
{
    int arr[] = {3, 5, 6, 7, 20, 8, 2, 9, 12, 15, 30, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int count = 0;

    heapSort(arr, size, &count);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}