#include <stdio.h>
#define MAXLEN 80

typedef struct rec {
        int roll;
        char name[MAXLEN];
        int score;
}rec;


void inputData(rec arr[], int n) {
        for (int i = 0; i< n; i++) {
                printf("Enter student %d roll: ",i+1);
                scanf("%d",&(arr[i].roll));
                printf("Enter student %d name: ",i+1);
                scanf("%s", arr[i].name);
                printf("Enter student %d score: ",i+1);
                scanf("%d", &(arr[i].score));
        }
}


void printData(rec arr[], int n) {
        printf("\nRoll\t\tName\t\tScore\n");
        for (int i = 0; i < n; i++) {
                printf("%d\t\t%s\t\t%d\n", arr[i].roll, arr[i].name, arr[i].score);
        }
}

void addData(rec arr[], int n) {
	re
	printf("Enter roll");
	scanf("%d", &(info->roll));
	printf("Enter name: ");
	scanf("%s", &(info->name));
	printf("Enter score: ");
	scanf("%d", &(info->score));

	arr[n+1] = 
}


int main() {
	rec arr[100];
	int n, ch;
	printf("Enter number of students: ");
	scanf("%d", &n);

	inputData(arr, n);
	printData(arr, n);

	int running = 1;
	while (running) {
		printf("Enter 1 to add, 2 to delete, 3 to quit\n");
		if (ch == 1) {
			
		}

		else if (ch == 2) {

		}

		else {
			running = 0;
		}
	}

	printf("Bye Bye");
	
	return 0;
}
