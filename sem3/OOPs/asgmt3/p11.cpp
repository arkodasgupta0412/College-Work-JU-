#include <iostream>
using namespace std;

class LinkedList;

class NODE
{
    int data;
    NODE *next;

public:
    // Constructor to initialize node
    NODE(int value = 0)
    {
        data = value;
        next = nullptr;
    }

    friend class LinkedList;
};

// LinkedList class to manage the list operations
class LinkedList
{
private:
    NODE *head; // Pointer to the first node of the list

public:
    LinkedList()
    {
        head = nullptr;
    }

    // Insert at the end of the list
    void insertAtEnd(int value)
    {
        NODE *newNode = new NODE(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            NODE *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Insert at the beginning of the list
    void insertAtBeginning(int value)
    {
        NODE *newNode = new NODE(value);
        newNode->next = head;
        head = newNode;
    }

    // Delete a node with a specific value
    void deleteNode(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->data == value)
        {
            NODE *temp = head;
            head = head->next;
            delete temp;
            cout << "Node with value " << value << " deleted." << endl;
            return;
        }

        NODE *temp = head;
        NODE *prev = nullptr;
        while (temp != nullptr && temp->data != value)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node with value " << value << " not found." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << "Node with value " << value << " deleted." << endl;
    }

    // Traverse and display the list
    void traverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }

        NODE *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Search for a node with a specific value
    bool search(int value)
    {
        NODE *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Destructor to free memory
    ~LinkedList()
    {
        NODE *temp;
        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to demonstrate the LinkedList operations
int main()
{
    LinkedList list;

    // Insert at the end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    // Insert at the beginning
    list.insertAtBeginning(5);

    // Display the list
    cout << "Linked List: ";
    list.traverse();

    // Delete a node
    list.deleteNode(20);
    cout << "After deletion: ";
    list.traverse();

    // Search for a node
    int value = 10;
    if (list.search(value))
    {
        cout << "Node with value " << value << " is found in the list." << endl;
    }
    else
    {
        cout << "Node with value " << value << " is not found in the list." << endl;
    }

    return 0;
}
