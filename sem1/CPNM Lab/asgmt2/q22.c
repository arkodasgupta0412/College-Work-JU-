#include <stdio.h>

int main()
{
    char ch;
    printf("Enter any character: ");
    scanf("%c", &ch);

    int ascii = (int)ch;

    if (ascii >= 65 && ascii <= 90)
    {
        printf("Upper case character\n");
    }

    else if (ascii >= 97 && ascii <= 122)
    {
        printf("Lower case character\n");
    }

    else if (ascii >= 48 && ascii <= 57)
    {
        printf("Digit character\n");
    }

    else
    {
        printf("Other special character\n");
    }
    return 0;
}