#include <stdio.h>

int main()
{
    char s[100], initials[100];
    int j = 1;

    printf("Enter string: ");
    scanf("%[^\n]c", s);

    initials[0] = s[0];
    for (int i = 1; s[i] != '\0'; ++i)
    {
        if (s[i] == ' ')
        {
            initials[j++] = s[i + 1];
        }
    }
    initials[j] = '\0';

    printf("%s\n", initials);

    return 0;
}