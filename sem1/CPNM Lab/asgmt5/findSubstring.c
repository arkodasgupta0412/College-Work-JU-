#include <stdio.h>

int findSubstring(char *str, char *substring);
void inputString(char *str, size_t max);

int main(void)
{
    char str[40], substr[40];
    printf("Enter the string: ");
    inputString(str, sizeof(str));
    printf("Enter the substring: ");
    inputString(substr, sizeof(str));
    printf("findSubstring(): %d\n", findSubstring(str, substr));
    return 0;
}

int findSubstring(char *str, char *substr)
{
    int i = 0, j = 0;
    while ((*(str + j) != '\0') && (*(substr + i) != '\0'))
    {
        if (*(substr + i) != *(str + j))
        {
            j++;
            i = 0;
        }
        else
        {
            i++;
            j++;
        }
    }

    if (*(substr + i) == '\0')
        return 1;
    else
        return -1;
}

void inputString(char *str, size_t max)
{
    int i;
    fgets(str, max, stdin);
    for (i = 0; *(str + i) != '\0'; i++)
    {
        if (*(str + i) == '\n')
        {
            *(str + i) = '\0';
            break;
        }
    }
}