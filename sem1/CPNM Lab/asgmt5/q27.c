#include <stdio.h>
#include <stdlib.h>
#define INITIAL_LENGTH 20

// forming new string removing all occurences of character c from string s
char *squeeze(char *s, char c)
{
    char *ns = (char *)malloc(INITIAL_LENGTH * sizeof(char));
    int i = 0, len = 0;

    while (s[i] != '\0')
    {
        if (s[i] != c)
        {
            ns[len++] = s[i];
        }
        ++i;
    }

    ns[len] = '\0';

    ns = (char *)realloc(ns, (len + 1) * sizeof(char));

    return ns;
}

int main(void)
{
    char *s = "abra-ca-dabra";
    char c = 'a';

    char *result = squeeze(s, c);
    printf("%s", result);

    free(result);
    result = NULL;

    return 0;
}