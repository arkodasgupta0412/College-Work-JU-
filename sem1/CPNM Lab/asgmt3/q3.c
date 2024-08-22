#include <stdio.h>

int main()
{
    int number, reversedNumber = 0;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate the reverse of the number
    while (number > 0)
    {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        number /= 10;
    }

    // Print the reverse of the number
    printf("Reverse of the given number is: %d\n", reversedNumber);

    return 0;
}
