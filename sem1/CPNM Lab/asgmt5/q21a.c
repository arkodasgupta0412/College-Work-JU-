#include <stdio.h>
#include <stdlib.h>

int isVowel(const char c)
{
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'o' || c == 'O' || c == 'i' || c == 'I' || c == 'u' || c == 'U');
}

int length(char *s)
{
    int l = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        l += 1;
    }
    return l;
}

char *inputString()
{

    char *s = (char *)malloc(50 * sizeof(char));
    char ch;
    int i = 0;

    while (1)
    {
        scanf("%c", &ch);
        if (ch == '\n')
        {
            break;
        }
        else
        {
            s[i++] = ch;
        }
    }

    s[i] = '\0';

    s = (char *)realloc(s, i * sizeof(char));

    return s;
}

// part (a)
int countWords(char *s)
{
    int c = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ' ')
        {
            c += 1;
        }
    }

    // in order to count the word which was missed earlier because there are no spaces in front
    c += 1;

    return c;
}

// part (c)
char *reverseString(char *s)
{
    char *revstring = (char *)malloc((length(s) + 1) * sizeof(char)); // +1 for the null-terminator
    int i;

    for (i = 0; i < length(s); ++i)
    {
        revstring[i] = s[length(s) - i - 1];
    }
    revstring[i] = '\0';

    return revstring;
}

// part (d)
void countVowelConso(char *s)
{
    int vowel = 0, conso;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (isVowel(s[i]))
        {
            vowel += 1;
        }
    }

    // consonants = length of string - number of spaces -  number of vowels
    // example: arko is a good boy  ; vowel = 7, conso = (18 - 4 - 7) = 7

    conso = length(s) - (countWords(s) - 1) - vowel;

    printf("Number of vowels in string: %d\n", vowel);
    printf("Number of consonants in string: %d\n", conso);
}

// part (e)
void maxCharFreq(char *s)
{
    // first making the unique string, i.e the string with only unique letters from the original string
    char *u = (char *)malloc(length(s) * sizeof(char));
    int len = 0;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        int is_unique = 1;

        for (int j = 0; j < len; ++j)
        {
            if (u[j] == s[i])
                is_unique = 0;
        }

        if (is_unique)
        {
            u[len++] = s[i];
        }
    }

    u[len] = '\0';

    u = (char *)realloc(u, len * sizeof(char));

    // Then I take one character from unique string and count occurence of that character in the original string
    // by comparing using a loop
    int max = 0, c = 0;
    char ch;

    for (int i = 0; u[i] != '\0'; ++i)
    {
        c = 0;
        for (int j = 0; s[j] != '\0'; ++j)
        {
            if (u[i] == s[j])
            {
                c += 1;
            }
        }

        if (c > max)
        {
            max = c;
            ch = u[i];
        }
    }

    printf("'%c' occurs maximum times (count = %d)\n", ch, max);
}

// part (f)
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

int main()
{
    char *string, *substr;
    string = inputString();

    scanf("%c", substr);

    // part (a)
    int noOfWords = countWords(string);

    // part (c)
    char *rev = reverseString(string);
    printf("%s\n", rev);

    // part (d)
    countVowelConso(string);

    // part (e)
    maxCharFreq(string);

    // part (f)
    int res = findSubstring(string, substr);
    if (res == -1)
    {
        printf("Substring is absent in the string\n");
    }
    else
    {
        printf("Substring is present in the string\n");
    }
}