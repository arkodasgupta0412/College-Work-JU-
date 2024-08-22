#include <stdio.h>

int main()
{
    int amt;
    printf("Enter amount to be withdrawn: Rs ");
    scanf("%d", &amt);

    printf("Denominations:\n");

    printf("100s: %d\n", amt / 100);
    printf("50s %d\n", (amt % 100) / 50);
    printf("10s: %d\n", ((amt % 100) % 50) / 10);
    printf("5s: %d\n", (((amt % 100) % 50) % 10) / 5);
    printf("1s: %d\n", ((((amt % 100) % 50) % 10) % 5));

    return 0;
}