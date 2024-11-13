#include "p8dll.c"
#include <stdio.h>
#include <stdbool.h>
#include "p6.c"
#include "utils.c"
#include <limits.h>

// Function prototypes for additional DLL operations
Node *createDLL(int);
void print_reverse(Node *head);
int size_of_list(Node *head);
bool are_lists_equal(Node *head1, Node *head2);
int search_key(Node **head, int key);
void append_list(Node **head1, Node *head2);
void delete_nth_node(Node **head, int n);
bool is_ordered(Node *head);
Node *merge_sorted_lists(Node *head1, Node *head2);
void insert_target_node(Node **head, int target, int before);
void remove_duplicates(Node **head);
void swap_pairwise(Node **head);
void move_last_to_front(Node **head);
void delete_alternate_nodes(Node **head);
void rotate_list(Node **head);
void reverse_list(Node **head);
void sort_list(Node **head, int op);

int main()
{
    int choice, data, key, position, size, op;
    Node *list1, *list2, *appendList, *mergedList;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Print List\n");
        printf("3. Print List in Reverse\n");
        printf("4. Find Size of List\n");
        printf("5. Check if Two Lists are Equal\n");
        printf("6. Search for a Key\n");
        printf("7. Append List\n");
        printf("8. Delete Nth Node\n");
        printf("9. Check if List is Ordered\n");
        printf("10. Merge Two Sorted Lists\n");
        printf("11. Insert Target Node\n");
        printf("12. Remove Duplicates\n");
        printf("13. Swap Elements Pairwise\n");
        printf("14. Move Last Element to Front\n");
        printf("15. Delete Alternate Nodes\n");
        printf("16. Rotate List\n");
        printf("17. Reverse List\n");
        printf("18. Sort List\n");
        printf("19. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter size of LinkedList: ");
            scanf("%d", &size);
            list1 = createDLL(size);
            break;

        case 2:
            printf("List: ");
            print(list1);
            break;

        case 3:
            printf("List in Reverse: ");
            print_reverse(list1);
            printf("NULL\n");
            break;

        case 4:
            printf("Size of List: %d\n", size_of_list(list1));
            break;

        case 5:
            printf("Enter size of another linked list: ");
            scanf("%d", &size);
            list2 = createDLL(size);
            print(list2);
            printf("Lists are %s\n", are_lists_equal(list1, list2) ? "Equal" : "Not Equal");
            break;

        case 6:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int foundNodeData = search_key(&list1, key);
            if (foundNodeData != INT_MAX)
            {
                printf("Key found and deleted: %d\n", foundNodeData);
            }
            else
            {
                printf("Key not found.\n");
            }
            break;

        case 7:
            printf("Enter size of another linked list: ");
            scanf("%d", &size);
            appendList = createDLL(size);
            print(appendList);
            append_list(&list1, appendList);
            break;

        case 8:
            printf("Enter position to delete (1-based index): ");
            scanf("%d", &position);
            delete_nth_node(&list1, position);
            break;

        case 9:
            printf("List is %sordered.\n", is_ordered(list1) ? "" : "not ");
            break;

        case 10:
            printf("Enter size of another linked list: ");
            scanf("%d", &size);
            list2 = createDLL(size);
            print(list1);
            print(list2);
            mergedList = merge_sorted_lists(list1, list2);
            printf("Merged Sorted List: ");
            print(mergedList);
            break;

        case 11:
            printf("Enter target value to insert: ");
            scanf("%d", &data);
            printf("Enter node value to insert before: ");
            scanf("%d", &key);
            insert_target_node(&list1, data, key);
            break;

        case 12:
            remove_duplicates(&list1);
            break;

        case 13:
            swap_pairwise(&list1);
            break;

        case 14:
            move_last_to_front(&list1);
            break;

        case 15:
            delete_alternate_nodes(&list1);
            break;

        case 16:
            rotate_list(&list1);
            break;

        case 17:
            reverse_list(&list1);
            printf("list reversed\n");
            break;

        case 18:
            printf("Enter comparator (0 for inc, 1 for dec): ");
            scanf("%d", &op);
            sort_list(&list1, op);
            printf("list sorted\n");
            break;

        case 19:
            printf("Exiting...\n");
            exit(0);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}

Node *createDLL(int size)
{
    Node *head = init_dll();
    int data;

    for (int i = 0; i < size; i++)
    {
        printf("Enter node %d: ", i + 1);
        scanf("%d", &data);
        insert_end(create(data), &head);
    }

    return head;
}

void print_reverse(Node *head)
{
    if (head == NULL)
        return;
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    while (tail != NULL)
    {
        printf("%d->", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

int size_of_list(Node *head)
{
    Node *p = head;
    int size = 0;
    while (p != NULL)
    {
        size++;
        p = p->next;
    }
    return size;
}

bool are_lists_equal(Node *head1, Node *head2)
{
    if (size_of_list(head1) != size_of_list(head2))
    {
        return false;
    }

    Node *p1 = head1, *p2 = head2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data != p2->data)
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

int search_key(Node **head, int key)
{
    if (*head == NULL)
        return INT_MAX;

    Node *cur = *head;
    while (cur != NULL)
    {
        if (cur->data == key)
        {
            int data = cur->data;
            if (cur->prev)
                cur->prev->next = cur->next;
            if (cur->next)
                cur->next->prev = cur->prev;
            if (cur == *head)
                *head = cur->next;
            free(cur);
            return data;
        }
        cur = cur->next;
    }
    return INT_MAX;
}

// Implement the rest of the functions similarly to your singly linked list version, adapting for doubly linked list specifics.
