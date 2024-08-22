#include <stdio.h>

int main()
{
    float a, b, c;

    printf("Enter three numbers: ");
    scanf("%f %f %f", &a, &b, &c);

    float arr[3];
    arr[0] = a, arr[1] = b, arr[2] = c;

    float max = arr[0], min = arr[0];
    for (int i = 1; i <= 2; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("Maximum number: %.2f\n", max);
    printf("Minimum number: %.2f\n", min);

    return 0;
}