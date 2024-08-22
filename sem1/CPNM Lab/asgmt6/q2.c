#include <stdio.h>

int main()
{
    char info[1000];
    FILE *f;
    f = fopen("data.txt", "w");

    printf("Enter information to store in the file:\n");
    scanf("%[^\n]", &info);

    fprintf(f, info);

    fclose(f);
    f = NULL;

    return 0;
}