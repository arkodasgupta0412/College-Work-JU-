#include <stdio.h>

int main(char *argv[])
{
    FILE *f, *f1;
    f = fopen(argv[1], "r");

    char c;
    while ((c = fgetc(f)) != EOF)
    {
        fputc(c, f1);
    }

    fclose(f);
    fclose(f1);

    f = fopen(argv[1], "r");
    while ((c = fgetc(f)) != EOF)
    {
        putchar(c);
    }

    fclose(f);

    f = NULL, f1 = NULL;

    return 0;
}