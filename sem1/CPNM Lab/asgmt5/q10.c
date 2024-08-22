#include <stdio.h>
#include <stdlib.h>

char *inputString()
{

	char *s = (char *)malloc(50 * sizeof(char));
	char ch;
	int i = 0;

	printf("Enter string: ");

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

int isVowel(char c)
{

	if (c == 'A' || c == 'a' || c == 'E' || c == 'e' || c == 'O' || c == 'o' || c == 'I' || c == 'i' || c == 'u' || c == 'U')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int countConsecutiveVowels(char *s)
{

	int i = 1, c = 0;
	while (s[i] != '\0')
	{
		if (isVowel(s[i - 1]) && isVowel(s[i]))
		{
			c += 1;
		}
		i++;
	}

	return c;
}

int main(void)
{

	char *s = inputString();

	printf("There are %d consecutive vowels in the string.", countConsecutiveVowels(s));

	free(s);
	s = NULL;

	return 0;
}
