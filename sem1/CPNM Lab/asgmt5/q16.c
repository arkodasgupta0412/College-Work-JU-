// integer to string

#include <stdio.h>
#include <stdlib.h>

int countDigit(int n)
{
    int c = 0;
    while (n)
    {
        c += 1, n /= 10;
    }
    return c;
}

char *itos(int n)
{
    char *s = (char *)malloc((countDigit(n) + 2) * sizeof(char));

    if (n == 0)
        return "0";

    else
    {
        int len = 0;

        int num = (n >= 0) ? n : -n;

        while (num)
        {
            s[len++] = num % 10 + '0';
            num /= 10;
        }

        if (n < 0)
        {
            s[len++] = '-';
        }

        s[len] = '\0';
        s = (char *)realloc(s, len * sizeof(char));

        // reversing string
        for (int i = 0; i < len / 2; ++i)
        {
            char tmp = s[i];
            s[i] = s[len - i - 1];
            s[len - i - 1] = tmp;
        }

        return s;
    }
}

int main()
{
    int n = 0;
    char *s = itos(n);

    printf("%s\n", s);
    return 0;
}