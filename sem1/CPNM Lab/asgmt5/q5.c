#include <stdio.h>

int countCharacters(const char s[])
{
	int c = 0;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		c += 1;
	}
	return c;
}

int main(void)
{

	char string[100];
	printf("Enter string: ");
	scanf("%[^\n]", &string);

	printf("Number of characters in string is %d\n", countCharacters(string));
	return 0;
}
