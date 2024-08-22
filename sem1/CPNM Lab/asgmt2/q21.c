#include <stdio.h>
#include <math.h>

int main()
{
    double centerX, centerY, radius, x, y;

    // input center of circle
    printf("Enter the center coordinates (x, y) of the circle: ");
    scanf("%lf %lf", &centerX, &centerY);

    // input radius of circle
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);

    // input other point to check
    printf("Enter the coordinates (x, y) of the point: ");
    scanf("%lf %lf", &x, &y);

    // distance between center and given point
    double distance = sqrt(pow((x - centerX), 2) + pow((y - centerY), 2));

    // comparing distance and radius to check location of point
    if (distance < radius)
    {
        printf("Point (%.2lf, %.2lf) is inside the circle.\n", x, y);
    }
    else if (distance == radius)
    {
        printf("Point (%.2lf, %.2lf) is on the circle.\n", x, y);
    }
    else
    {
        printf("Point (%.2lf, %.2lf) is outside the circle.\n", x, y);
    }

    return 0;
}
