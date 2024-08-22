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

int checkPalindrome(char *s)
{
    int len = getLength(s), flag = 0;
    printf("%d\n", len);

    for (int i = 0; i < len / 2; ++i)
    {
        if (s[i] != s[len - i - 1])
        {
            flag = 1;
            break;
        }
    }

    // flag = 0 -> palindrome
    // flag = 1 -> not palindrome

    if (flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(void)
{

    char *s = inputString();

    if (checkPalindrome(s) == 1)
    {
        printf("Palindrome");
    }

    else
    {
        printf("Not palindrome");
    }

    free(s);
    s = NULL;
    return 0;
}