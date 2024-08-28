#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));

    FILE *fp;
    if ((fp = fopen("data1.txt", "w+")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    for (int i = 0; i < 10; i++)
    {
        char s[12];
        for (int j = 0; j < 10; j++)
        {
            s[j] = (char)(65 + rand() % 26);
        }
        s[10] = '\n';
        s[11] = '\0';
        fputs(s, fp);
    }

    fclose(fp);

    return 0;
}