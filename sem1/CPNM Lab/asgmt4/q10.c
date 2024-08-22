#include <stdio.h>

void writeToFile(FILE *file, int original, int larger, int smaller, int difference)
{
    fprintf(file, "%d %d %d %d\n", original, larger, smaller, difference);
}

int kaprekarRoutine(int number)
{
    FILE *outputFile = fopen("output.dat", "w");

    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        return -1;
    }

    int count = 0;
    int constant = 6174; // Kaprekar Constant
    int currentNumber = number;

    do
    {
        int digits[4];
        int larger, smaller, difference;

        // Extract digits
        for (int i = 3; i >= 0; i--)
        {
            digits[i] = currentNumber % 10;
            currentNumber /= 10;
        }

        // Arrange digits in descending order
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i - 1; j++)
            {
                if (digits[j] < digits[j + 1])
                {
                    int temp = digits[j];
                    digits[j] = digits[j + 1];
                    digits[j + 1] = temp;
                }
            }
        }

        // Form larger and smaller numbers
        larger = digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
        smaller = digits[3] * 1000 + digits[2] * 100 + digits[1] * 10 + digits[0];

        // Calculate the difference
        difference = larger - smaller;

        // Write to output file
        writeToFile(outputFile, currentNumber, larger, smaller, difference);

        // Update current number for the next iteration
        currentNumber = difference;
        printf("number after iteration %d: %d\n", count + 1, currentNumber);
        count++;
    } while (currentNumber != constant);

    fclose(outputFile);

    return count;
}

int main()
{
    int startingNumber;

    printf("Enter a four-digit number with at least two different digits: ");
    scanf("%d", &startingNumber);

    int steps = kaprekarRoutine(startingNumber);

    if (steps != -1)
    {
        printf("Kaprekar Constant is reached in %d steps.\n", steps);
    }

    return 0;
}
