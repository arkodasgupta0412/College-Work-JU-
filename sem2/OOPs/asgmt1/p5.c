#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** allocateNames(int num) {
	char** name = (char**)malloc(num * sizeof(char*));
	for (int i = 0; i < num; i++) {
		name[i] = (char*)malloc(80 * sizeof(char));
	}
	return name;
}

int* allocateAge(int num) {
	return (int*)malloc(num * sizeof(int));
}

void inputData(char** name, int* age, int num) {
	for (int i = 0; i < num; i++) {
		printf("Enter the age of student: ");
		scanf("%d", &age[i]);
		printf("Enter name of student: ");
		scanf("%s", name[i]);
	}
}

void sortBasedOnAge(char** name, int* age, int num) {
	for (int i = 0; i< num; i++) {
		for (int j = 0;  j < num-i-1; j++) {
			if (age[j] > age[j+1]) {
				int t = age[j];
				age[j] = age[j+1];
				age[j+1] = t;

				char t1[80];
				strcpy(t1, name[i]);
				strcpy(name[i], name[i+1]);
				strcpy(name[i+1], t1);
			}
		}
	}
}

void display(char** name, int* age, int num) {
	printf("Name\t\tAge\n");
	for (int i = 0; i < num; i++) {
		printf("%s\t\t%d\n", name[i], age[i]);
	}
}

int main() {
	int n;
	printf("Enter number of students: ");
	scanf("%d", &n);

	char** name = allocateNames(n);
	int* age = allocateAge(n);

	inputData(name, age, n);

	sortBasedOnAge(name, age, n);

	display(name, age, n);

	// freeing memory
	for (int i = 0; i< n; i++) {
		free(name[i]);
	}
	free(name);

	free(age);

	return 0;
}
