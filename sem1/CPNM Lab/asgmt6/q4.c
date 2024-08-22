#include <stdio.h>

typedef struct student
{
    char name[40];
    int roll;
    int marks[6];

} student;

void sort(float a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (a[j] < a[j + 1])
            {
                float tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    student record[5];
    for (int i = 0; i < 5; ++i)
    {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Enter name: ");
        scanf(" %[^\n]", &record[i].name);
        printf("Enter roll: ");
        scanf("%d", &record[i].roll);
        printf("Enter marks in 6 subjects: ");
        for (int j = 0; j < 6; ++j)
        {
            scanf("%d", &record[i].marks[j]);
        }
    }

    float avg[5], tmp[5];
    for (int i = 0; i < 5; ++i)
    {
        float sum = 0.0;
        for (int j = 0; j < 6; ++j)
        {
            sum += record[i].marks[j];
        }
        avg[i] = sum / 6.0;
    }

    for (int i = 0; i < 5; ++i)
    {
        tmp[i] = avg[i];
    }

    sort(avg, 5);

    printf("\nRank List:\n");
    printf("Name\t\tRoll\t\tAverage\n");
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (avg[i] == tmp[j])
            {
                printf("%s\t\t\t%d\t\t\t%.2f\n", record[j].name, record[j].roll, avg[i]);
            }
        }
    }

    return 0;
}