#include <stdio.h>

int main()
{
    // Input values
    double hardness, carbonContent, tensileStrength;

    printf("Enter hardness, carbon content, and tensile strength of the steel: ");
    scanf("%lf %lf %lf", &hardness, &carbonContent, &tensileStrength);

    // Check conditions and determine grade
    int grade;

    if (hardness > 50 && carbonContent < 0.7 && tensileStrength > 5600)
    {
        grade = 10;
    }
    else if (hardness > 50 && carbonContent < 0.7)
    {
        grade = 9;
    }
    else if (carbonContent < 0.7 && tensileStrength > 5600)
    {
        grade = 8;
    }
    else if (hardness > 50 && tensileStrength > 5600)
    {
        grade = 7;
    }
    else if (hardness > 50 || carbonContent < 0.7 || tensileStrength > 5600)
    {
        grade = 6;
    }
    else
    {
        grade = 5;
    }

    // Output the grade
    printf("Grade of the steel: %d\n", grade);

    return 0;
}
