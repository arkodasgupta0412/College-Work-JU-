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

    // s[i] = ' ';
    s[i] = '\0';

    s = (char *)realloc(s, i * sizeof(char));

    return s;
}

int main(void)
{

    char *s = inputString();
    int c = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ')
            c += 1;
    }

    // we print c+1 because last word will not be included in this algo
    // another thing that can be done is first inserting space at last of string and then doing this algo
    printf("Count of words: %d\n", c + 1);

    free(s);
    s = NULL;
    return 0;
}