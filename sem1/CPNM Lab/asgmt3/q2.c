#include <stdio.h>

int main()
{
    int number, originalNumber, sum = 0;

    // Input the number from the user
    printf("Enter a number: ");
    scanf("%d", &number);

    // Save the original number for reference
    originalNumber = number;

    // Calculate the sum of digits
    while (number > 0)
    {
        int digit = number % 10;
        sum += digit;
        number /= 10;
    }

    // Print the sum of digits
    printf("Sum of digits of %d is: %d\n", originalNumber, sum);

    return 0;
}
