#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXLEN 80

typedef struct Student
{
    struct data
    {
        int roll;
        char name[MAXLEN];
        int score;
    } data;

    struct Student *next;

} Student;

void insert(Student **head)
{
    Student *ptr = (Student *)malloc(sizeof(Student));
    Student *ptr1;
    ptr->next = NULL;

    int r, s;
    char n[MAXLEN];

    printf("\nEnter roll of student: ");
    scanf("%d", &(ptr->data).roll);

    printf("Enter name of student: ");
    scanf("%s", (ptr->data).name);

    printf("Enter score of student: ");
    scanf("%d", &(ptr->data).score);

    if (*head == NULL)
    {
        *head = ptr;
    }

    else
    {
        ptr1 = *head;
        while (ptr1->next != NULL)
        {
            ptr1 = ptr1->next;
        }
        ptr1->next = ptr;
    }
}

void delete(Student **head, int roll)
{
    Student *p1 = *head, *p2 = p1->next;

    if ((p1->data).roll == roll)
    {
        *head = p2;
        free(p1);
        return;
    }

    if (p2 == NULL)
    {
        printf("\nRoll not found\n");
        return;
    }

    while (p2->next != NULL)
    {
        if ((p2->data).roll == roll)
        {
            break;
        }
        p2 = p2->next;
        p1 = p1->next;
    }

    if (p2->next == NULL)
    {
        printf("\nRoll not found\n");
        return;
    }

    p1->next = p2->next;
    free(p2);
}

void display(Student *head)
{
    Student *ptr = (Student *)malloc(sizeof(Student));
    ptr = head;

    int i = 1;

    printf("\n\t\t\t\tTABLE\nS.No\t\t\tRoll\t\t\tName\t\t\tScore\n");

    while (ptr != NULL)
    {
        printf("%d\t\t\t%d\t\t\t%s\t\t\t%d\n", i++, (ptr->data).roll, (ptr->data).name, (ptr->data).score);
        ptr = ptr->next;
    }
}

int main()
{
    Student *head = NULL;

    bool running = true;
    int ch, r;

    while (running)
    {
        printf("\nEnter choice:\n1. Insert Record\n2. Delete Record\n3. Display Record\n4. Exit\n\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert(&head);
            break;

        case 2:
            if (head == NULL)
            {
                printf("Can't delete data from empty table. Pls insert\n");
            }
            else
            {
                printf("Enter roll to delete: ");
                scanf("%d", &r);
                delete (&head, r);
            }
            break;

        case 3:
            display(head);
            break;

        case 4:
            printf("Thank You\n");
            running = false;
            break;

        default:
            printf("Invalid Choice. Enter again\n");
            break;
        }
    }

    return 0;
}