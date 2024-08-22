#include <stdio.h>
#include <stdlib.h>

int main(void)
{

	char ch;
	char *s1 = (char *)malloc(100 * sizeof(char));
	int len = 0;

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
			s1[len++] = ch;
		}
	}
	s1[len] = '\0';

	char *s2 = (char *)malloc(len * sizeof(char));
	int i;

	for (i = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == ' ')
		{
			s2[i] = '|';
		}
		else
		{
			s2[i] = s1[i];
		}
	}
	s2[i] = '\0';

	printf("Modified string: %s\n", s2);

	free(s1);
	free(s2);

	s1 = NULL;
	s2 = NULL;

	return 0;
}
