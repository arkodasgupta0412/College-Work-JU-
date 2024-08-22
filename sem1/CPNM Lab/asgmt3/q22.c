#include <stdio.h>

int main(void)
{
    printf("From ascii 0 to 31 and from 127 to 255, the characters are not printable.\n");

    printf("\nFrom 32 to 126:\n\n");
    printf("ascii\t\tcharacter\n");
    for (int i = 32; i <= 126; ++i)
    {
        printf("%d\t\t%c\n", i, (char)i);
    }
    return 0;
}