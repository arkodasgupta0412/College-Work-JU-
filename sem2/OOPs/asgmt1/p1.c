#include <stdio.h>

int main() {
	int x;
	printf("Enter value of x: ");
	scanf("%d", &x);

	int *p = &x;
	int **pp = &p;

	printf("Value of x using pointer p: %d\n",*p);
	printf("Value of x using pointer to pointer p: %d\n ",**pp);

	return 0;
}
