#include <stdio.h>

int s = 0, p = 1;

int binary(int n)
{

	if (n == 0)
	{
		return s;
	}

	else
	{
		s += (n % 2) * p;
		p *= 10;
		return binary(n / 2);
	}
}

int main()
{
	int n, bin;

	printf("Enter decimal: ");
	scanf("%d", &n);

	bin = binary(n);
	printf("Binary: %d\n", bin);
	return 0;
}
