#include <stdio.h>
#define PI 3.14

int main()
{
    float r, l, b;
    printf("Enter radius of circle, length and breadth of rectangle: ");
    scanf("%f %f %f", &r, &l, &b);

    // rectangle
    printf("Perimeter of rectangle: %.2f\n", 2 * (l + b));
    printf("Area of rectangle: %.2f\n", l * b);

    // area
    printf("Circumference of circle: %.2f\n", 2 * PI * r);
    printf("Area of circle: %.2f\n", PI * r * r);

    return 0;
}