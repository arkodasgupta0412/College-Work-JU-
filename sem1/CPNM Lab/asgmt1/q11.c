#include <stdio.h>
#define TOTAL 500

int main()
{
    float marks, sum = 0.0;
    int i = 0;

    printf("Enter marks of student in 5 subjects:\n");

    while (i < 5)
    {
        printf("subject %d: ", i + 1);
        scanf("%f", &marks);

        if (marks > 100)
        {
            printf("Marks cannot be greater than total marks 100\nEnter again\n");
        }

        else
        {
            sum += marks;
            i += 1;
        }
    }

    printf("Total marks out of 500: %.1f\n", sum);
    printf("Percentage: %.2f %%\n", (sum / TOTAL) * 100.0);

    return 0;
}