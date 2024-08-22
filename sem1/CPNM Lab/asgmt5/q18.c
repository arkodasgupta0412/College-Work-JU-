#include <stdio.h>

int stringLength(char *s)
{
    if (*s == '\0')
        return 0;
    else
        return 1 + stringLength(s + 1);
}

int main()
{
    char *string = "I love programming";

    printf("The length of string is %d\n", stringLength(string));

    return 0;
}