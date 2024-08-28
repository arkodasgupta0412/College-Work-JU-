#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100
#define NUMBER 100

void sortAscending(char names[][MAX_LEN], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(names[j], names[j + 1]) > 0)
            {
                char tmp[MAX_LEN];
                strcpy(tmp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tmp);
            }
        }
    }
}

void writeNewFile(FILE *f, char names[][MAX_LEN], int i)
{
    f = fopen("newname.txt", "w");

    for (int j = 0; j < i; j++)
    {
        fputs(strcat(names[j], "\n\0"), f);
    }
    fclose(f);
}

int main()
{

    FILE *fp, *fp1;
    char name[MAX_LEN];
    char max_name[MAX_LEN];
    char min_name[MAX_LEN];
    size_t max_length = 0;
    size_t min_length = MAX_LEN;
    char names[NUMBER][MAX_LEN];
    int i = 0;

    if ((fp = fopen("names.txt", "r")) == NULL)
    {
        printf("Cannot open file\n");
        exit(1);
    }

    while (fgets(name, MAX_LEN, fp) != NULL)
    {
        strcpy(names[i++], name);
        size_t len = strlen(name);
        if (name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
            len--;
        }

        if (len > max_length)
        {
            max_length = len;
            strcpy(max_name, name);
        }

        if (len < min_length)
        {
            min_length = len;
            strcpy(min_name, name);
        }
    }

    printf("max length: %d, name = %s\n", max_length, max_name);
    printf("min length: %d, name = %s\n", min_length, min_name);

    sortAscending(names, i);
    writeNewFile(fp1, names, i);

    fclose(fp);

    return 0;
}