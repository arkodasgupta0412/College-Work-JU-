#include <iostream>
#define MAX 100
using namespace std;

class Stack
{
    int top, size;
    int arr[MAX];

public:
    Stack(int x)
    {
        /* constructor for empty stack */
        if (x > MAX)
        {
            cout << "Maximum size can be " << MAX << endl;
            return;
        }
        top = -1;
        size = x;
    }

    int isEmpty()
    {
        /* checks whether stack is empty or not. returns 1 if empty, else 0 */
        return (top == -1);
    }

    int isFull()
    {
        /* checks whether stack is full or not. returns 1 if full, else 0 */
        return (top == size - 1);
    }

    int push(int x)
    {
        /* pushes new element into stack if stack not full, returns 0, if success else -1 */
        if (!isFull())
        {
            arr[++top] = x;
            return 0;
        }
        cout << "Stack overflow" << endl;
        return -1;
    }

    int pop()
    {
        /* pops element from a non-empty stack, if popped, returns popped value, else -1 */
        if (!isEmpty())
        {
            int x = arr[top--];
            return x;
        }
        cout << "Stack underflow" << endl;
        return -1;
    }

    int peek()
    {
        /* returns the topmost element of the stack */
        return arr[top];
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            if (i == top)
            {
                cout << arr[i] << " <-- top" << endl;
            }
            else
            {
                cout << arr[i] << endl;
            }
        }
    }
};