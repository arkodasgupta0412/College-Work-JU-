#include <stdio.h>

int main()
{
    float a, b, c, s1, s2, s3;

    // using angles
    printf("Enter three angles of triangle: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a + b + c == 180)
    {
        printf("It forms a triangle\n");
    }
    else
    {
        printf("It does not form a triangle\n");
    }

    // using sides
    printf("Enter three sides of triangle: ");
    scanf("%f %f %f", &s1, &s2, &s3);

    if (s1 + s2 > s3 && s2 + s3 > s1 && s3 + s1 > s2)
    {
        printf("It forms a triangle\n");
    }
    else
    {
        printf("It does not form triangle\n");
    }
}