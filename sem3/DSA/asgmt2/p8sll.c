#include "p8sll.h"

Node *init_l()
{
    return NULL;
}

Node *create(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int empty_l(Node *head)
{
    return (head == NULL);
}

int atend_l(Node *curr)
{
    return (curr->next == NULL);
}

void insert_front(Node *target, Node **head)
{
    target->next = (*head);
    *head = target;
}

void insert_after(Node *target, Node **prev)
{
    if ((*prev) == NULL)
    {
        printf("Previous node is NULL; cannot insert\n");
        return;
    }
    target->next = (*prev)->next;
    (*prev)->next = target;
}

void delete_front(Node **head)
{
    if (*head == NULL)
    {
        printf("List empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void delete_after(Node **prev)
{
    if ((*prev) == NULL || (*prev)->next == NULL)
    {
        printf("No element to delete after given node\n");
        return;
    }
    Node *temp = (*prev)->next;
    (*prev)->next = temp->next;
    free(temp);
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* int main()
{
    Node *l1 = init_l();
    Node *n1 = create(5);
    Node *n2 = create(10);
    Node *n3 = create(8);
    Node *n4 = create(3);
    Node *n5 = create(11);

    insert_front(n1, &l1); // Insert n1 at the front
    print(l1);

    insert_after(n2, &n1); // Insert n2 after n1
    print(l1);

    insert_front(n3, &l1); // Insert n3 at the front
    print(l1);

    insert_after(n4, &n3); // Insert n4 after n3
    print(l1);

    insert_after(n5, &n1); // Insert n5 after n1
    print(l1);

    delete_front(&l1); // Delete front node
    print(l1);

    delete_after(&n5); // Delete after n3
    print(l1);
} */