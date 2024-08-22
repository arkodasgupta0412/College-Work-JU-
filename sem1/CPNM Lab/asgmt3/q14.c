#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b;
    printf("Enter value of a and b for log_b(a): ");
    scanf("%f %f", &a, &b);

    // to find: log_b(a) = ln(a) / ln(b)
    printf("Log of %.2f to the base %.2f = log_%.2f(%.2f) =  %.2f\n", a, b, b, a, log(a) / log(b));

    return 0;
}