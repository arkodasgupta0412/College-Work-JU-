#include <stdio.h>

typedef struct student
{
    int roll;
    char name[40];
    char dept[40];
    char course[10];
    int year;
} student;

int main()
{
    student record[5];
    for (int i = 0; i < 5; ++i)
    {
        printf("\nEnter details of student %d:\n", i + 1);
        printf("Enter roll: ");
        scanf("%d", &record[i].roll);
        printf("Enter name: ");
        scanf(" %[^\n]", &record[i].name);
        printf("Enter department: ");
        scanf(" %[^\n]", &record[i].dept);
        printf("Enter course: ");
        scanf(" %[^\n]", &record[i].course);
        printf("Enter year of joining: ");
        scanf("%d", &record[i].year);
    }

    // print names of students who joined in particular year
    int y;
    printf("\nEnter year: ");
    scanf("%d", &y);

    printf("List of students who joined in %d:\n", y);
    for (int i = 0; i < 5; ++i)
    {
        if (record[i].year == y)
        {
            printf("%s\n", record[i].name);
        }
    }

    // print data of student whose roll is given
    int roll;
    printf("\nEnter roll: ");
    scanf("%d", &roll);

    printf("Data:\n");
    for (int i = 0; i < 5; ++i)
    {
        if (record[i].roll == roll)
        {
            printf("Roll\t\tName\t\tDepartment\t\tCourse\t\tYear Of Joining\n");
            for (int j = 0; j < 5; ++j)
            {
                printf("%d\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%d\n", record[i].roll, record[i].name, record[i].dept, record[i].course, record[i].year);
                break;
            }
        }
    }

    return 0;
}