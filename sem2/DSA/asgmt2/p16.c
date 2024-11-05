#include <stdio.h>
#include <string.h>
#include "generate.c"
#include "heapsort.c"
#include "utils.h"
#include <time.h>

long long bubbleSort(int arr[], int size)
{
    long long cmp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            cmp++;
            if (arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
    return cmp;
}

long long insertionSort(int arr[], int size)
{
    long long cmp = 0;
    for (int i = 1; i < size; i++)
    {
        int key = arr[i], j = i - 1;
        while (j >= 0)
        {
            cmp++;
            if (arr[j] <= key)
                break;

            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return cmp;
}

long long selectionSort(int arr[], int size)
{
    long long cmp = 0;
    for (int i = 0; i < size; i++)
    {
        int mn = arr[i], mnIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            cmp++;
            if (arr[j] < mn)
            {
                mn = arr[j];
                mnIdx = j;
            }
        }
        int t = arr[i];
        arr[i] = mn;
        arr[mnIdx] = t;
    }
    return cmp;
}

void merge(int arr[], int low, int mid, int high, int *cmp)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int leftArr[n1], rightArr[n2];
    for (int i = 0; i < n1; i++)
    {
        leftArr[i++] = arr[low + i];
    }
    for (j = 0; j < n2; j++)
    {
        rightArr[j++] = arr[mid + 1 + j];
    }

    i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        (*cmp)++;
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = leftArr[i++];
    }

    while (j < n2)
    {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int arr[], int low, int high, int *cmp)
{
    if (low < high)
    {
        int mid = (low + high) >> 1;
        mergeSort(arr, low, mid, cmp);
        mergeSort(arr, mid + 1, high, cmp);
        merge(arr, low, mid, high, cmp);
    }
}

void heapsort(int arr[], int size, int *cmp)
{
    heapSort(arr, size, cmp);
}

void copy(int source[], int destination[], int size)
{
    memcpy(destination, source, size * sizeof(int));
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int size = 80000;
    int arr[size];
    generate(arr, size);
    clock_t t_start, t_end;
    double time_bubble, time_insertion, time_selection, time_merge, time_heap;

    int bArr[size], iArr[size], sArr[size], mArr[size], hArr[size];

    // Bubble Sort
    copy(arr, bArr, size);
    t_start = clock();
    long long cmpbs = bubbleSort(bArr, size);
    t_end = clock();
    time_bubble = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Comparisons: %lld\n", cmpbs);
    printf("Bubble Sort Time: %.2f seconds\n\n", time_bubble);

    // Insertion Sort
    copy(arr, iArr, size);
    t_start = clock();
    long long cmpis = insertionSort(iArr, size);
    t_end = clock();
    time_insertion = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Comparisons: %lld\n", cmpis);
    printf("Insertion Sort Time: %.2f seconds\n\n", time_insertion);

    // Selection Sort
    copy(arr, sArr, size);
    t_start = clock();
    long long cmpss = selectionSort(sArr, size);
    t_end = clock();
    time_selection = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    printf("Selection Sort Comparisons: %lld\n", cmpss);
    printf("Selection Sort Time: %.2f seconds\n\n", time_selection);

    // Merge Sort
    copy(arr, mArr, size);
    int cmpms = 0;
    t_start = clock();
    mergeSort(mArr, 0, size - 1, &cmpms);
    t_end = clock();
    time_merge = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    printf("Merge Sort Comparisons: %d\n", cmpms);
    printf("Merge Sort Time: %.2f seconds\n\n", time_merge);

    // Heap Sort
    copy(arr, hArr, size);
    int cmphs = 0;
    t_start = clock();
    heapsort(hArr, size, &cmphs);
    t_end = clock();
    time_heap = ((double)(t_end - t_start)) / CLOCKS_PER_SEC;
    printf("Heap Sort Comparisons: %d\n", cmphs);
    printf("Heap Sort Time: %.2f seconds\n\n", time_heap);

    return 0;
}