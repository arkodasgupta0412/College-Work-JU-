#include <stdio.h>

int main()
{
    int seconds;
    printf("Enter time in seconds: ");
    scanf("%d", &seconds);

    int h = seconds / 3600;
    int m = (seconds - (h * 3600)) / 60;
    int s = (seconds - (h * 3600) - (m * 60));

    printf("Time: %d hours %d minutes %d seconds\n", h, m, s);

    return 0;
}