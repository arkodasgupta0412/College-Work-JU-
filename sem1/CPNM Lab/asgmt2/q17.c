#include <stdio.h>

int main()
{
    char word[6], decodedWord[6];
    int i;

    printf("Enter a 5 letter encoded word: ");
    scanf("%[^\n]c", word);

    for (i = 0; word[i] != '\0'; ++i)
    {
        decodedWord[i] = (char)((int)word[i] + 30);
    }
    decodedWord[i] = '\0';

    printf("Decoded word: %s\n", decodedWord);
    return 0;
}