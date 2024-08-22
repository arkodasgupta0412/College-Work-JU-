#include <stdio.h>

int main()
{
    float salary;
    printf("Enter salary: ");
    scanf("%f", &salary);

    float gross = salary + (0.15 * salary) + (0.6 * salary);

    printf("Gross salary: %.2f\n", gross);

    return 0;
}