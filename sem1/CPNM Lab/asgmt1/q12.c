#include <stdio.h>
#include <math.h>
#define PI 3.14

int main()
{
    float length, breadth;
    printf("Enter length and breadth of rectangle: ");
    scanf("%f %f", &length, &breadth);

    // case 1: area of rectangle = area of circle
    printf("\nCASE1: AREA OF RECTANGLE =  AREA OF CIRCLE\n");
    float radius = sqrt((length * breadth) / PI);
    // ratio of perimeter of rectangle to circle
    float r1 = ((2 * (length + breadth)) / (2 * PI * radius));
    printf("Radius of circle: %.3f\n", radius);
    printf("Ratio of perimeter of rectangle to circumference of circle: %.3f\n", r1);

    // case 2: perimeter of rectangle = circumference of circle
    printf("\nCASE2: PERIMETER OF RECTANGLE = CIRCUMFERENCE OF CIRCLE\n");
    float radius1 = ((2 * (length + breadth)) / (2 * PI));
    float r2 = ((length * breadth) / (PI * radius1 * radius1));
    printf("Radius of circle: %.3f\n", radius1);
    printf("Ratio of area of rectangle to area of circle: %.3f\n", r2);

    return 0;
}