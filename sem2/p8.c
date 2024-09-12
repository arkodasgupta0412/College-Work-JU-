#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void convertAndPrintSum(char full_name[])
{
    char largeIntStr[1000] = "";

    for (int i = 0; i < strlen(full_name); i++)
    {
        char asciiStr[4];
        sprintf(asciiStr, "%d", (int)full_name[i]);
        strcat(largeIntStr, asciiStr);
    }

    printf("\nLarge Integer: %s\n", largeIntStr);

    int len = strlen(largeIntStr), mid = len / 2;

    // Splitting string into two halves
    char firstHalf[500], secondHalf[500];
    strncpy(firstHalf, largeIntStr, mid);
    firstHalf[mid] = '\0';

    strcpy(secondHalf, largeIntStr + mid);

    printf("\nFirst Half: %s\n", firstHalf);
    printf("Second Half: %s\n", secondHalf);

    // Converting halves to integers
    long long int firstHalfInt = atoll(firstHalf);
    long long int secondHalfInt = atoll(secondHalf);

    // Adding two halves
    long long int sum = firstHalfInt + secondHalfInt;

    printf("\nSum of the two halves: %lld\n", sum);
}

int main()
{
    char first_name[100];
    char last_name[100];

    printf("Enter your first name: ");
    scanf("%s", first_name);

    printf("Enter your last name: ");
    scanf("%s", last_name);

    convertAndPrintSum(strcat(first_name, last_name));

    return 0;
}
