#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "student.dat"

typedef struct Student
{
    int roll;
    char name[50];
    int scores[5];
    int isDeleted;
} Student;

void addRecord(const char *fn);
void displayAllRecords(const char *fn);
void searchRecord(const char *fn);
void editRecord(const char *fn);
void physicalDelete(const char *fn);
void logicalDelete(const char *fn);

int main()
{
    int choice;
    while (1)
    {
        printf("\n--- Student Information System ---\n");
        printf("1. Add Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record\n");
        printf("4. Edit Record\n");
        printf("5. Delete Record (Logical)\n");
        printf("6. Delete Record (Physical)\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addRecord(FILENAME);
            break;
        case 2:
            displayAllRecords(FILENAME);
            break;
        case 3:
            searchRecord(FILENAME);
            break;
        case 4:
            editRecord(FILENAME);
            break;
        case 5:
            logicalDelete(FILENAME);
            break;
        case 6:
            physicalDelete(FILENAME);
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addRecord(const char *fn)
{
    Student student, temp;
    FILE *fp = fopen(fn, "ab+");

    printf("Enter roll number: ");
    scanf("%d", &student.roll);

    while (fread(&temp, sizeof(temp), 1, fp))
    {
        if (temp.roll == student.roll && temp.isDeleted == 0)
        {
            printf("Roll already exists.\n");
            fclose(fp);
            return;
        }
    }

    printf("Enter name: ");
    scanf("%s", student.name);

    printf("Enter marks in 5 subjects: ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &student.scores[i]);
    }

    student.isDeleted = 0;

    fwrite(&student, sizeof(student), 1, fp);

    fclose(fp);
    printf("Record added successfully");
}

void displayAllRecords(const char *fn)
{
    Student temp;

    FILE *fp = fopen(fn, "rb");

    printf("\n--- All Student Records ---\n");
    printf("Roll\t\tName\t\t\tTotal Score\n");
    while (fread(&temp, sizeof(temp), 1, fp))
    {
        // only printing valid records
        if (temp.isDeleted == 0)
        {
            int ts = 0;
            for (int i = 0; i < 5; i++)
            {
                ts += temp.scores[i];
            }
            printf("%d\t\t%s\t\t\t%d\n", temp.roll, temp.name, ts);
        }
    }
    fclose(fp);
}

void searchRecord(const char *fn)
{
    Student temp;
    int roll;
    FILE *fp = fopen(fn, "rb");

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    while (fread(&temp, sizeof(temp), 1, fp))
    {
        if (temp.roll == roll && temp.isDeleted == 0)
        {
            int ts = 0;
            for (int i = 0; i < 5; i++)
            {
                ts += temp.scores[i];
            }
            printf("%d\t\t%s\t\t\t%d\n", temp.roll, temp.name, ts);
        }
        fclose(fp);
        return;
    }

    printf("No record found\n");
    fclose(fp);
}

void editRecord(const char *fn)
{
    int roll;
    Student student;
    FILE *fp = fopen(fn, "rb+");

    int ch, i;

    printf("Enter Roll Number to edit: ");
    scanf("%d", &roll);

    while (fread(&student, sizeof(student), 1, fp))
    {
        if (student.roll == roll && student.isDeleted == 0)
        {
            printf("Which field you want to edit?\n1. Name\n2. Marks\n3. Exit\n");
	    scanf("%d", &ch);

	    if (ch >= 3) break;
	    if (ch == 1) {
		printf("Enter Name: ");
		scanf("%s", student.name);
	    }
	    if (ch == 2) {
		printf("Which marks[1-5]: ");
		scanf("%d", &i);
		printf("Enter marks: ");
		scanf("%d", &student.scores[i-1]);
	    }

	    fseek(fp, -sizeof(student), SEEK_CUR);
	    fwrite(&student, sizeof(student), 1, fp);
	    printf("Data edited");
	    fclose(fp);
	    return;
	}
    }

    if (feof(fp)) {
	printf("Record not found.\n");
    }

    fclose(fp);
    return;
}

void logicalDelete(const char *fn)
{
    int roll;
    Student student;
    FILE *fp = fopen(fn, "rb+");

    printf("Enter Roll Number to delete (logical): ");
    scanf("%d", &roll);

    while (fread(&student, sizeof(student), 1, fp))
    {
        if (student.roll == roll && student.isDeleted == 0)
        {
            student.isDeleted = 1; // Mark record as deleted
            fseek(fp, -sizeof(student), SEEK_CUR);
            fwrite(&student, sizeof(student), 1, fp);
            fclose(fp);
            printf("Record deleted (logically) successfully.\n");
            fclose(fp);
            return;
        }

        else if (student.roll == roll && student.isDeleted == 1)
        {
            printf("Record already been deleted before. But physically present in file\n");
            fclose(fp);
            return;
        }
    }

    printf("Record not found.\n");
    fclose(fp);
}

void physicalDelete(const char *fn)
{
    int roll;
    struct Student student;
    FILE *fp = fopen(fn, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    printf("Enter Roll Number to delete (physical): ");
    scanf("%d", &roll);

    while (fread(&student, sizeof(student), 1, fp))
    {
        if (student.roll != roll || student.isDeleted == 1)
        {
            fwrite(&student, sizeof(student), 1, temp);
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILENAME);
    rename("temp.dat", FILENAME);

    printf("Record deleted (physically) successfully.\n");
}
