#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    float avg = (float)(a + b + c) / 3;

    printf("Average value: %.2f\n", avg);

    // a
    {
        if (a > avg)
            printf("%d is above average\n", a);

        else if (a == avg)
            printf("%d is same as average\n", a);

        else
            printf("%d is below average\n", a);
    }

    {
        if (b > avg)
            printf("%d is above average\n", b);

        else if (b == avg)
            printf("%d is same as average\n", b);

        else
            printf("%d is below average\n", b);
    }

    {
        if (c > avg)
            printf("%d is above average\n", c);

        else if (c == avg)
            printf("%d is same as average\n", c);

        else
            printf("%d is below average\n", c);
    }

    return 0;
}