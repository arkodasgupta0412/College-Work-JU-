#include <stdio.h>
#define MAXLEN 80

typedef struct rec
{
	int roll;
	char name[MAXLEN];
	int score;
} rec;

int cmp(int a, int b)
{
	return (a > b);
}

void inputData(rec arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter student %d roll: ", i + 1);
		scanf("%d", &(arr[i].roll));
		printf("Enter student %d name: ", i + 1);
		scanf("%s", arr[i].name);
		printf("Enter student %d score: ", i + 1);
		scanf("%d", &(arr[i].score));
	}
}

void customSortScore(rec arr[], int n, int (*fp)(int, int))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (fp(arr[j].score, arr[j + 1].score))
			{
				rec t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void customSortRoll(rec arr[], int n, int (*fp)(int, int))
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (fp(arr[j].roll, arr[j + 1].roll))
			{
				rec t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
		}
	}
}

void printData(rec arr[], int n)
{
	printf("\nRoll\t\tName\t\tScore\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d\t\t%s\t\t%d\n", arr[i].roll, arr[i].name, arr[i].score);
	}
}

int main()
{
	int n;
	printf("Enter number of students: ");
	scanf("%d", &n);

	rec arr[n];
	int (*fp)(int, int);
	fp = cmp;

	inputData(arr, n);

	int ch;
	printf("\nEnter choice:\n1. Sort based on Roll\n2. Sort based on Score\n");
	scanf("%d", &ch);

	if (ch == 1)
	{
		customSortRoll(arr, n, fp);
	}

	else
	{
		customSortScore(arr, n, fp);
	}

	printData(arr, n);

	return 0;
}
