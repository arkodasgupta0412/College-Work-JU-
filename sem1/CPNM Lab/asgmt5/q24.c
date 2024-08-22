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
    char str1[100], str2[100];
    int i;

    printf("Enter string: ");
    scanf("%[^\n]c", str1);

    int len = length(str1);

    printf("Original string: %s\n", str1);

    for (i = 0; i < len; ++i)
    {
        str2[i] = str1[len - i - 1];
    }

    str2[i] = '\0';

    printf("Reversed String: %s\n", str2);

    return 0;
}