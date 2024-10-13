#include <iostream>
#include <string.h>
#define MAX 100
#define MAXNAME 20
using namespace std;

class ItemList;

class Item
{
    int code;
    char name[MAXNAME];
    float rate;
    int qty;

public:
    void get()
    {
        cout << "Enter item code, name, rate and quantity: ";
        cin >> code >> name >> rate >> qty;
    }

    friend class ItemList;
};

class ItemList
{
    Item list[MAX];
    static int count;
    int checkUnique(int code)
    {
        for (int i = 0; i < count; i++)
        {
            /* not unique */
            if (list[i].code == code)
                return 0;
        }
        /* unique */
        return 1;
    }

    int search(const char c[])
    {
        for (int i = 0; i < count; i++)
        {
            if (!strcmp(list[i].name, c))
                return i;
        }
        return -1;
    }

public:
    int add()
    {
        /* returns 0 on successful addition, else -1 */
        Item i;
        i.get();
        if (checkUnique(i.code))
        {
            list[count++] = i;
            return 0;
        }
        cout << "Item code not unique" << endl;
        return -1;
    }

    int changeRate(const char c[], float r)
    {
        /* returns 0 on successful rate change, else -1 */
        int pos = search(c);
        if (pos != -1)
        {
            list[pos].rate = r;
            return 0;
        }
        cout << "Item not found\n";
        return -1;
    }

    int getItem(const char c[], int q)
    {
        /* returns 0 on successful purchase, else -1, if purchase qty > stock, returns 1 */
        int pos = search(c);
        if (pos != -1)
        {
            if (list[pos].qty < q)
            {
                cout << "Only " << q << " in stock\n";
                return 1;
            }
            else
            {
                list[pos].qty -= q;
            }
            return 0;
        }
        cout << "Item not found\n";
        return -1;
    }

    float getPrice(const char c[])
    {
        /* returns 0 if item found, prints price, else returns -1 */
        int pos = search(c);
        if (pos != -1)
        {
            cout << "Rs " << list[pos].rate * list[pos].qty << endl;
            return 0;
        }
        cout << "item not found\n";
        return -1;
    }

    void show()
    {
        cout << "\nCode\t\tName\t\tRate\t\tQuantity" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << list[i].code << "\t\t" << list[i].name << "\t\t" << list[i].rate << "\t\t" << list[i].qty << endl;
        }
    }
};

int ItemList::count = 0;

int main()
{
    ItemList list;
    list.add();
    list.add();
    list.add();
    list.show();

    list.changeRate("shoe", 5.212);
    list.show();

    list.changeRate("bag", 12.12);
    list.show();

    list.getItem("bag", 2);
    list.show();

    list.getItem("shoe", 5);
    list.show();

    list.getPrice("table");
    list.show();
}