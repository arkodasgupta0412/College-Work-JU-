#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    FILE *fp;
    if ((fp = fopen("data.txt", "w+")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        int rn = 1 + rand() % 100000;
        char str[100000];
        sprintf(str, "%d", rn);
        fputs(strcat(str, "\n\0"), fp);
    }

    fclose(fp);

    return 0;
}