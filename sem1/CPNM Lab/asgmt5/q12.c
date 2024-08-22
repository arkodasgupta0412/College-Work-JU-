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
    int len = 0;

    while (s[len] != '\0')
    {
        len++;
    }

    return len;
}

int StringToInt(char *s)
{
    int num = 0, len = getLength(s);

    for (int i = 0; s[i] != '\0'; ++i)
    {
        num = num * 10 + (s[i] - '0');
    }

    return num;
}

int main(void)
{

    char *s = inputString();

    printf("String to int: %d\n", StringToInt(s));

    free(s);
    s = NULL;
    return 0;
}