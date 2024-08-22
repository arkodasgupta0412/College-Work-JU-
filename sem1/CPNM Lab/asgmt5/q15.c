#include <stdio.h>
#include <stdlib.h>

int getLength(char *s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        l += 1;
    }
    return l;
}

char *removeSpaces(char *s)
{
    char *s1 = (char *)malloc(getLength(s) * sizeof(char));
    int len = 0, c = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ')
        {
            c += 1;
            if (c == 1)
                s1[len++] = ' ';
        }

        else
        {
            c = 0;
            s1[len++] = s[i];
        }
    }

    s1[len] = '\0';

    s1 = (char *)realloc(s1, len * sizeof(char));

    return s1;
}

int main(void)
{
    char *s = "He  is a    very   good boy";
    char *ns = removeSpaces(s);

    printf("%s\n%s\n", s, ns);
    return 0;
}