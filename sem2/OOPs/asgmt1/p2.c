#include <stdio.h>
#include <stdlib.h>

int main() {
	int size;
	printf("Enter the size of the array: ");
	scanf("%d", &size);

	int* p = (int*)malloc(size * sizeof(int));

	// accepting values of array elements
	for (int i = 0; i < size; i++) {
		scanf("%d", p+i);
	}

	printf("Array elements:\n");
	// printing values of array elements
	for (int i = 0; i < size; i++) {
		printf("%d ", *(p+i));
	}
	printf("\n");

	return 0;
}

