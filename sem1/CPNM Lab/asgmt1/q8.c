#include <stdio.h>

int main()
{
    float fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);

    float centigrade = (5.0 / 9.0) * (fahrenheit - 32.0);

    printf("Temperature in centigrade: %.2f\n", centigrade);
    return 0;
}