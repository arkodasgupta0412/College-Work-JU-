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

char *convert(int n, int w)
{
}

int main()
{
    int n = 1234567, width = 10;
    // output: "   1234567"

    int n1 = 12345, width1 = 3;
    // output: "123"

    char *s = convert(n, width);
    char *s1 = convert(n1, width1);

    printf("%s\n", s);
    printf("%s\n", s1);

    return 0;
}