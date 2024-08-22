#include <stdio.h>
#include <math.h>
#define PI 3.14
#define EPSILON 0.00001

double factorial(int x)
{
    double f = 1;
    int i = 1;
    while (i <= x)
    {
        f *= i;
        i++;
    }

    return f;
}

int main(void)
{

    double x, s = 0.0, sign = 1.0, term;
    int i = 0;

    printf("Enter x: ");
    scanf("%lf", &x);
    printf("sin(%.2lf) = ", x);

    // bringing x in [-pi, pi] interval to increase the convergence rate of the Taylor series
    while (x > PI)
    {
        x -= 2 * PI;
    }

    while (x < -PI)
    {
        x += 2 * PI;
    }

    // actual value for testing
    // printf("%.8lf\n", sin(x));

    do
    {
        term = sign * (pow(x, 2 * i + 1) / factorial(2 * i + 1));
        s += term;
        sign *= -1, i++;
    } while (fabs(term) > EPSILON);

    printf("%.8lf\n", s);

    return 0;
}
