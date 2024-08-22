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

    // printing highest and second highest marks of each subject

    int student, student1;
    for (int i = 0; i < 5; ++i)
    {
        int highest = 0, second_highest = 0;
        for (int j = 0; j < 5; ++j)
        {
            if (rec[j][i] > highest)
            {
                highest = rec[j][i];
                student = j + 1;
            }
        }

        for (int j = 0; j < 5; ++j)
        {
            if (rec[j][i] < highest && rec[j][i] > second_highest)
            {
                second_highest = rec[j][i];
                student1 = j + 1;
            }
        }
        printf("\nHighest marks obtained in subject %d = %d by student %d\n", i + 1, highest, student);
        printf("Second highest marks obtained in subject %d = %d by student %d\n", i + 1, second_highest, student1);
    }

    return 0;
}