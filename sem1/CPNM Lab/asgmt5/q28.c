#include <stdio.h>
#include <stdlib.h>

char *inputString()
{

    char *s = (char *)malloc(50 * sizeof(char));
    char ch;
    int i = 0;

    while (1)
    {
        scanf("%c", &ch);
        if (ch == '\n')
        {
            break;
        }
        else
        {
            s[i++] = ch;
        }
    }

    s[i] = '\0';

    s = (char *)realloc(s, i * sizeof(char));

    return s;
}

int getLength(char *s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        l += 1;
    }

    return l;
}

int strend(char *string, char *substring)
{
    int lenString = getLength(string), lenSubstring = getLength(substring), j = 0, flag = 0;
    char *lastWord = (char *)malloc((lenSubstring + 1) * sizeof(char));

    // extracting last word
    for (int i = lenString - lenSubstring; i <= lenString - 1; ++i)
    {
        lastWord[j] = string[i];
        j++;
    }

    lastWord[j] = '\0';

    // printf("%s %s\n", lastWord, substring);

    // comparing last word and substring
    for (int i = lenSubstring - 1; i >= 0; --i)
    {
        // last word is not substring
        if (lastWord[i] != substring[i])
        {
            flag = 1;
            break;
        }
    }

    // last word = substring
    if (flag == 0)
    {
        return 1;
    }

    // last word != substring
    else
    {
        return 0;
    }
}

int main()
{
    char *s, *s1;

    printf("\nEnter string: ");
    s = inputString();

    printf("Enter substring to check: ");
    s1 = inputString();

    if (strend(s, s1) == 1)
    {
        printf("\nSubstring is same as last word of string.\n");
    }
    else
    {
        printf("\nSubstring is not same as last word of string\n");
    }
}