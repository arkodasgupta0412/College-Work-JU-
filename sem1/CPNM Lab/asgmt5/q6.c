#include <stdio.h>

int length(const char s[])
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        l += 1;
    }
    return l;
}

int main()
{
    char s[100], revs[100];
    int i;

    printf("Enter string: ");
    scanf("%[^\n]c", s);

    int len = length(s);

    printf("Original string: %s\n", s);

    for (i = 0; i < len; ++i)
    {
        revs[i] = s[len - i - 1];
    }

    revs[i] = '\0';

    printf("Reversed String: %s\n", revs);

    return 0;
}