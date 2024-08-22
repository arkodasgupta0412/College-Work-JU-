#include <stdio.h>
#include <stdlib.h>

int getLength(char *s)
{
    int c = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        c += 1;
    }
    return c;
}

char *uniqueString(char *s)
{
    char *u = (char *)malloc(getLength(s) * sizeof(char));
    int len = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        int is_unique = 1;

        for (int j = 0; j < len; ++j)
        {
            if (u[j] == s[i])
                is_unique = 0;
        }

        if (is_unique)
        {
            u[len++] = s[i];
        }
    }

    u[len] = '\0';

    u = (char *)realloc(u, len * sizeof(char));

    return u;
}

void maxCharFreq(char *s, char *u)
{
    int max = 0, c = 0;
    char ch;

    for (int i = 0; u[i] != '\0'; ++i)
    {
        c = 0;
        for (int j = 0; s[j] != '\0'; ++j)
        {
            if (u[i] == s[j])
            {
                c += 1;
            }
        }

        if (c > max)
        {
            max = c;
            ch = u[i];
        }
    }

    printf("'%c' occurs maximum times (count = %d)\n", ch, max);
}

int main()
{
    char *s = "abra-ca-dabra";
    char *u = uniqueString(s);

    printf("given string: %s\n\n", s);

    maxCharFreq(s, u);

    return 0;
}