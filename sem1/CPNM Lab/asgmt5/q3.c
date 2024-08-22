#include <stdio.h>

int s = 0;

int sumDigits(int n)
{

	if (!n)
	{
		return s;
	}

	else
	{
		s += n % 10;
		return sumDigits(n / 10);
	}
}

int main(void)
{
	int n;
	printf("Enter number: ");
	scanf("%d", &n);
	printf("Sum of digits of %d is %d\n", n, sumDigits(n));
	return 0;
}
