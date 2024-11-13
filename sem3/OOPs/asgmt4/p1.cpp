#include <iostream>
#define SIZE 20
using namespace std;

typedef long long ll;

class Bank;
class AccountList;

class Account
{
    ll accno;
    float balance;

public:
    // constructor for account
    Account() {}
    Account(ll x, float y) : accno(x), balance(y) {}
    friend class AccountList;
    friend class Bank;
};

class AccountList
{
    Account arr[SIZE];
    static int count;

    int unique()
    {
        /* checks unique account number */
    }

public:
    AccountList() {}

    int add(Account &a)
    {
        /* returns 0 if account added, else 1 */
        for (int i = 0; i < count; i++)
        {
            if (arr[i].accno == a.accno)
            {
                cout << "Account number already exists" << endl;
                return 1;
            }
        }
        arr[count++] = a;
        return 0;
    }

    int get(ll x)
    {
        /* returns the index of the searched account number if found, else -1 */

        for (int i = 0; i < count; i++)
        {
            if (arr[i].accno == x)
            {
                cout << "Account Number: " << arr[i].accno << "\nBalance: " << arr[i].balance << "\n";
                return i;
            }
        }
        cout << "No such account exists\n";
        return -1;
    }

    int withdraw(ll x, float y)
    {
        /* returns 0 on successful withdrawal, else 1 */
        int k = get(x);
        if (k != -1)
        {
            if (arr[k].balance >= y)
            {
                arr[k].balance -= y;
                cout << "Successful withdrawal. Remaining: " << arr[k].balance << endl;
                return 0;
            }
            else
            {
                cout << "Insufficient Balance. Remaining: " << arr[k].balance << endl;
                return -1;
            }
        }
        else
        {
            return 1;
        }
    }

    void show()
    {
        cout << "\nAccount Number\t\t\tBalance\n";
        for (int i = 0; i < count; i++)
        {
            cout << arr[i].accno << "\t\t\t" << arr[i].balance << endl;
        }
    }

    friend class Bank;
};

int AccountList::count = 0;

class Bank
{
    AccountList list;

public:
    void system()
    {
        bool running = true;
        while (running)
        {
            int ch;
            cout << "\nWelcome to HDFC Bank\n1. Add\n2. Show\n3. Search\n4. Withdraw\n5. Exit\n";
            cin >> ch;

            switch (ch)
            {
            case 1:
            {
                ll x;
                float y;
                cout << "Enter Account number: ";
                cin >> x;
                cout << "Enter balance: ";
                cin >> y;
                Account a(x, y);
                list.add(a);
                cout << "Account added\n";
                break;
            }

            case 2:
            {
                list.show();
                break;
            }

            case 3:
            {
                ll x;
                cout << "Enter account number: ";
                cin >> x;
                list.get(x);
                break;
            }

            case 4:
            {
                ll x;
                float y;
                cout << "Enter Account number: ";
                cin >> x;
                cout << "Enter balance: ";
                cin >> y;

                list.withdraw(x, y);
                break;
            }

            case 5:
            {
                cout << "Bye bye\n";
                running = false;
                break;
            }

            default:
            {
                cout << "Invalid option\n";
                break;
            }
            }
        }
    }
};

int main()
{
    Bank hdfc;
    hdfc.system();

    return 0;
}