#include <stdio.h>
#include <stdlib.h>

char *inputString()
{

	char *s = (char *)malloc(100 * sizeof(char));
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

int getLength(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}

	return len;
}

int main(void)
{

	char *s = inputString();
	int len = getLength(s), i;

	char *ns = (char *)malloc(len * sizeof(char));

	for (i = 0; s[i] != '\0'; ++i)
	{
		if ((int)s[i] >= 97 && (int)s[i] <= 122)
		{
			ns[i] = (char)((int)s[i] - 32);
		}
		else
		{
			ns[i] = s[i];
		}
	}

	ns[i] = '\0';

	printf("String in upper case: %s\n", ns);

	free(s);
	free(ns);
	s = NULL, ns = NULL;
	return 0;
}
