#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW_SIZE 100
#define col 100

/* -------------------------------------- 1D Array Implementation ---------------------------------------------*/

void getDim(int *n)
{
	printf("Enter the size of array: ");
	scanf("%d", n);
}

int *allocateMemory(int n)
{
	int *arr = (int *)malloc(n * sizeof(int));
	return arr;
}

void inputValues(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter element %d: ", i + 1);
		scanf("%d", arr + i);
	}
}

void display(int *arr, int n)
{
	printf("You entered array: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
}

/* ---------------------------------------- 2D Array Implementation ------------------------------------------- */

void get2Dim(int *r, int *c)
{
	printf("\n\nEnter number of rows and cols: ");
	scanf("%d %d", r, c);
}

int **allocateMemory1(int r, int c)
{
	int *a[r];

	for (int i = 0; i < r; i++)
	{
		a[i] = (int *)malloc(c * sizeof(int));
	}

	int **arr = a;
	return arr;
}

int **allocateMemory2(int r, int c)
{
	int **arr = (int **)malloc(r * sizeof(int *));
	for (int i = 0; i < r; i++)
	{
		*(arr + i) = (int *)malloc(c * sizeof(int));
	}
	return arr;
}

int **allocateMemory3(int r, int c)
{
	int **arr = (int **)malloc(r * sizeof(int *) + (r * c) * sizeof(int));

	for (int i = 0; i < r; i++)
	{
		arr[i] = arr[0] + (i + 1) * c;
	}
	return arr;
}

int (*allocateMemory4(int r, int c))[col]
{
	int(*arr)[c] = malloc(sizeof(int[c]));
	return arr;
}

void input2Values(int **arr, int r, int c)
{
	printf("Enter matrix elements:\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", *(arr + i) + j);
		}
	}
}

void display2(int **arr, int r, int c)
{
	printf("\nYou entered matrix:\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

void inputPtrToArrVal(int (*arr)[col], int r, int c)
{
	printf("\nEnter matrix elements:\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			scanf("%d", *(arr + i) + j);
		}
	}
}

void displayPtrToArrValues(int (*arr)[col], int r, int c)
{
	printf("\nYou entered matrix:\n");
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}

int main()
{
	// 1d array
	int n;
	getDim(&n);
	int *arr = allocateMemory(n);
	inputValues(arr, n);
	display(arr, n);

	// 2d array
	int r, c;
	get2Dim(&r, &c);

	// using two malloc
	printf("\nUsing Two Malloc...\n");
	int **a2 = allocateMemory2(r, c);
	input2Values(a2, r, c);
	display2(a2, r, c);

	// using one malloc
	printf("\nUsing One Malloc...\n");
	int **a3 = allocateMemory2(r, c);
	input2Values(a3, r, c);
	display2(a3, r, c);

	// using pointer to an array
	int(*a4)[c] = allocateMemory4(r, c);
	inputPtrToArrVal(a4, r, c);
	displayPtrToArrValues(a4, r, c);

	return 0;
}
