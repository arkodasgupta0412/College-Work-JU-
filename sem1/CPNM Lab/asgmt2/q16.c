#include <stdio.h>

int main()
{
    char word[6], encodedWord[6];
    int i;

    printf("Enter a 5 letter word: ");
    scanf("%[^\n]c", word);

    for (i = 0; word[i] != '\0'; ++i)
    {
        encodedWord[i] = (char)((int)word[i] - 30);
    }
    encodedWord[i] = '\0';

    printf("Encoded word: %s\n", encodedWord);
    return 0;
}