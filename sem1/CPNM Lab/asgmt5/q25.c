#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *alternateMerge(char *s1, char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2), flag = 0, len = 0, j, i;
    char *small, *large;

    if (l1 > l2)
        small = s2, large = s1;
    else
        small = s1, large = s2;

    char *s = (char *)malloc((l1 + l2 + 1) * sizeof(char));

    for (i = 0; small[i] != '\0'; ++i)
    {
        if (flag == 0)
        {
            s[len++] = small[i];
            flag = 1;
        }

        if (flag == 1)
        {
            s[len++] = large[i];
            flag = 0;
        }
    }

    if (l1 != l2)
    {
        for (j = i; large[j] != '\0'; ++j)
        {
            s[len++] = large[j];
        }
    }

    s[len] = '\0';

    return s;
}

int main()
{
    char *s1 = "abcd", *s2 = "efghijkl", *s3 = "efgh";

    char *s = alternateMerge(s1, s2);
    char *s0 = alternateMerge(s1, s3);

    printf("%s\n%s\n", s, s0);
}