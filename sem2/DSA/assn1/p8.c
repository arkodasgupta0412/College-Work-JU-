#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertAndPrintSum(char name[])
{
    char largeIntStr[1000] = "";

    for (int i = 0; i < strlen(name); i++)
    {
        char asciiStr[4];
        sprintf(asciiStr, "%d", (int)name[i]);
        strcat(largeIntStr, asciiStr);
    }

    printf("Large Integer: %s\n", largeIntStr);

    int len = strlen(largeIntStr), mid = len / 2;

    // Splitting string into two halves
    char firstHalf[500], secondHalf[500];
    strncpy(firstHalf, largeIntStr, mid);
    firstHalf[mid] = '\0';

    strcpy(secondHalf, largeIntStr + mid);

    // Converting halves to integers
    long long int firstHalfInt = atoll(firstHalf);
    long long int secondHalfInt = atoll(secondHalf);

    // Adding two halves
    long long int sum = firstHalfInt + secondHalfInt;

    printf("Sum of the two halves: %lld\n", sum);
}

int main()
{
    char name[100];
    char surname[100];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your surname: ");
    scanf("%s", surname);

    printf("\nFor Name:\n");
    convertAndPrintSum(name);

    printf("\nFor Surname:\n");
    convertAndPrintSum(surname);

    return 0;
}
