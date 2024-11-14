#include <stdio.h>
#include <string.h>
#include "p8sll.c"
#define LEN 100

Node *createNumList(char num[])
{
    Node *head = init_l();

    for (int i = 0; i < strlen(num); i++)
    {
        insert_front(createNode(num[i] - '0'), &head);
    }
    return head;
}

Node *add(Node *n1, Node *n2)
{
    Node *sum = init_l(), *t1 = n1, *t2 = n2;
    int carry = 0, s;

    while (t1 != NULL && t2 != NULL)
    {
        s = (t1->data + t2->data + carry) % 10;
        insert_front(createNode(s), &sum);

        carry = (t1->data + t2->data + carry) / 10;
        t1 = t1->next;
        t2 = t2->next;
    }

    while (t1 != NULL)
    {
        s = (t1->data + carry) % 10;
        insert_front(createNode(s), &sum);
        carry = (t1->data + carry) / 10;
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        s = (t2->data + carry) % 10;
        insert_front(createNode(s), &sum);
        carry = (t2->data + carry) / 10;
        t2 = t2->next;
    }

    if (carry)
    {
        insert_front(createNode(carry), &sum);
    }

    return sum;
}

Node *subtract(Node *n1, Node *n2)
{
    Node *result = init_l();
    Node *t1 = n1, *t2 = n2;
    int borrow = 0;

    while (t1 != NULL || t2 != NULL)
    {
        int digit1 = t1 ? t1->data : 0;
        int digit2 = t2 ? t2->data : 0;

        // Apply borrow if needed
        digit1 -= borrow;

        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        int diff = digit1 - digit2;
        insert_front(createNode(diff), &result);

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }

    // Remove leading zeros in result
    while (result && result->data == 0)
    {
        Node *temp = result;
        result = result->next;
        free(temp);
    }

    return result ? result : createNode(0); // Return 0 if result is empty
}

int main()
{
    char num1[LEN], num2[LEN];
    printf("Enter large number 1: ");
    scanf("%s", num1);
    printf("Enter large number 2: ");
    scanf("%s", num2);

    Node *n1 = createNumList(num1);
    Node *n2 = createNumList(num2);

    print(n1);
    print(n2);

    Node *sum = add(n1, n2);
    Node *diff = subtract(n1, n2);
    print(sum);
    print(diff);
}