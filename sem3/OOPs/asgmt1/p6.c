#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 80

typedef struct rec
{
	int age;
	char name[MAXLEN];
} rec;

void inputData(rec *arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = malloc(sizeof(rec));
		printf("Enter student %d name: ", i + 1);
		scanf("%s", arr[i]->name);
		printf("Enter student %d age: ", i + 1);
		scanf("%d", &(arr[i]->age));
	}
}

void sortByAge(rec *arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j]->age > arr[j + 1]->age)
			{
				rec *t1;
				t1 = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t1;
			}
		}
	}
}

void printData(rec *arr[], int n)
{
	printf("Name\t\tAge\n");
	for (int i = 0; i < n; i++)
	{
		printf("%s\t\t%d\n", arr[i]->name, arr[i]->age);
	}
}

int main()
{
	int n;
	printf("Enter number of students: ");
	scanf("%d", &n);

	rec *arr[n];

	inputData(arr, n);
	sortByAge(arr, n);
	printData(arr, n);

	// freeing mem
	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}

	return 0;
}
