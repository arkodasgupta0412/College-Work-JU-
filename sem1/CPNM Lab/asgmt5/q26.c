#include <stdio.h>
#include <stdlib.h>

char *makeNewString(char *s1, char *s2, int pos)
{
    char *s = (char *)malloc(15 * sizeof(char));
    int i = 0, j = 0;
    while (i < pos)
    {
        s[i] = s1[i];
        i++;
    }

    while (s2[j] != '\0')
    {
        s[i] = s2[j];
        i++, j++;
    }

    s[i] = '\0';

    s = (char *)realloc(s, i * sizeof(char));

    return s;

    free(s);
    s = NULL;
}

int main(void)
{
    char *s1 = "abcd", *s2 = "pqrs";
    int pos = 3;

    char *s = makeNewString(s1, s2, pos);

    printf("%s\n", s);

    return 0;
}