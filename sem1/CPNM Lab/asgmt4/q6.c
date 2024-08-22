#include <stdio.h>

int main()
{
    int rec[5][5];

    // accepting records of students
    for (int i = 0; i < 5; ++i)
    {
        printf("Enter marks of 5 subjects of students %d: ", i + 1);
        for (int j = 0; j < 5; ++j)
        {
            scanf("%d", &rec[i][j]);
        }
    }

    printf("\n");

    int max_total = 0, student;

    for (int i = 0; i < 5; ++i)
    {
        int total = 0;
        for (int j = 0; j < 5; ++j)
        {
            total += rec[i][j];
        }

        printf("Total marks of student %d = %d\n", i + 1, total);

        if (total > max_total)
        {
            max_total = total;
            student = i + 1;
        }
    }

    printf("\nHighest total marks obtained by student %d = %d\n", student, max_total);
}