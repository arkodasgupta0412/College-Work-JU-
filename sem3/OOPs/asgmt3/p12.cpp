#include <iostream>
#include <string>
using namespace std;

class Item
{
    int code;
    string name;
    double rate;
    int qty;

public:
    Item(int code = 0, string name = "", double rate = 0.0, int qty = 0) : code(code), name(name), rate(rate), qty(qty) {}

    int getCode() const
    {
        return code;
    }

    int getQuantity()
    {
        return qty;
    }

    float getRate()
    {
        return rate;
    }

    void updateQuantity(int q)
    {
        qty = q;
    }

    void changeRate(double newRate)
    {
        rate = newRate;
    }

    void display()
    {
        cout << code << "\t\t" << name << "\t\t" << rate << "\t\t" << qty << "\n";
    }
};
class ItemList
{
    Item *list;
    int size;
    int capacity;
    bool isUnique(int code)
    {
        for (int i = 0; i < size; i++)
        {
            if (list[i].getCode() == code)
                return false;
        }
        return true;
    }

    int search(int code)
    {
        for (int i = 0; i < size; i++)
        {
            if (list[i].getCode() == code)
            {
                return i;
            }
        }
        return -1;
    }

public:
    ItemList(int n)
    {
        list = new Item[n];
        capacity = n;
        size = 0;
    }
    void addItem(int code, string name, double rate, int qty)
    {
        if (!isUnique(code))
        {
            cout << "\nCode not unique" << "\n";
            return;
        }
        if (size == capacity)
        {
            cout << "\nList is full\n";
            return;
        }
        list[size] = Item(code, name, rate, qty);
        size++;
    }

    void issueItem(int code, int qty)
    {
        int pos = search(code);
        if (pos != -1)
        {
            int q = list[pos].getQuantity();
            if (q < qty)
            {
                cout << "\nOnly " << q << " items are left in stock\n";
            }
            else
            {
                list[pos].updateQuantity(q - qty);
            }
        }
        else
        {
            cout << "\nItem not present in list\n";
        }
    }

    void receiveItem(int code, int qty)
    {
        int pos = search(code);
        if (pos != -1)
        {
            int q = list[pos].getQuantity();
            list[pos].updateQuantity(q + qty);
        }
        else
        {
            string s;
            double r;
            cout << "\nNew item being added...\n";
            cout << "Item name: ";
            cin >> s;
            cout << "Rate: ";
            cin >> r;
            addItem(code, s, r, qty);
        }
    }

    void getItemPrice(int code)
    {
        int pos = search(code);
        if (pos != -1)
        {
            int q = list[pos].getQuantity();
            double r = list[pos].getRate();
            cout << "\nDetails of Item code-" << code << "\n";
            cout << "Price:" << q * r << ", Quantity:" << q << "\n";
        }
        else
        {
            cout << "\nItem not in list\n";
        }
    }

    void updateRate(int code, double newRate)
    {
        int pos = search(code);
        if (pos != -1)
        {
            double r = list[pos].getRate();
            r = newRate;
            cout << "\nRate updated to new rate\n";
        }
        else
        {
            cout << "\nItem not in list\n";
        }
    }

    void show()
    {
        cout << "\nCode\t\tName\t\tRate\t\tQty\n";
        for (int i = 0; i < size; i++)
        {
            list[i].display();
        }
    }
};
int main()
{
    ItemList ilist(5);
    ilist.addItem(1213, "Bag", 0.5, 10);
    ilist.addItem(12798, "Fan", 7, 8);
    ilist.show();
    ilist.receiveItem(1213, 7);
    ilist.issueItem(12798, 5);
    ilist.show();
    ilist.getItemPrice(1213);
}