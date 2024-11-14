#include <iostream>
#include <string>
using namespace std;

class Balance; // Forward declaration of Balance

class Transaction
{
    string account_number;
    string date_of_transaction;
    double amount;
    char transaction_type; // 'W' for Withdrawal, 'D' for Deposit

public:
    Transaction(string acc_num, string trans_date, double amt, char trans_type)
        : account_number(acc_num), date_of_transaction(trans_date), amount(amt), transaction_type(trans_type) {}

    void executeTransaction(Balance &); // Declare executeTransaction here
};

class Balance
{
    string account_number;
    double balance;
    string date_last_update;

public:
    Balance(string acc_num, double bal, string last_update)
        : account_number(acc_num), balance(bal), date_last_update(last_update) {}

    void showAccountDetails() const
    {
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
        cout << "Last Update Date: " << date_last_update << endl;
    }

    friend void Transaction::executeTransaction(Balance &);
};

// Define executeTransaction after Balance knows it's a friend
void Transaction::executeTransaction(Balance &balance)
{
    if (account_number == balance.account_number)
    {
        if (transaction_type == 'D')
        {
            balance.balance += amount;
            balance.date_last_update = date_of_transaction;
            cout << "Deposit of Rs " << amount << ". Balance: " << balance.balance << endl;
        }
        else
        {
            if (balance.balance >= amount)
            {
                balance.balance -= amount;
                balance.date_last_update = date_of_transaction;
                cout << "Withdrawal of Rs " << amount << ". Balance remaining: " << balance.balance << endl;
            }
            else
            {
                cout << "Withdrawal of Rs " << amount << endl;
                cout << "Insufficient funds for withdrawal! Balance remaining: " << balance.balance << endl;
            }
        }
    }
    else
    {
        cout << "Transaction failed! Account number mismatch." << endl;
    }
}

int main()
{
    Balance myAccount("ACC12345", 1000.0, "2024-10-05");

    // Display initial account details
    myAccount.showAccountDetails();
    cout << endl;

    // Perform a deposit transaction
    Transaction t1("ACC12345", "2024-10-06", 500.0, 'D');
    t1.executeTransaction(myAccount);
    myAccount.showAccountDetails();
    cout << endl;

    // Perform a withdrawal transaction
    Transaction t2("ACC12345", "2024-10-07", 700.0, 'W');
    t2.executeTransaction(myAccount);
    myAccount.showAccountDetails();
    cout << endl;

    // Try to withdraw an amount greater than the balance
    Transaction t3("ACC12345", "2024-10-08", 1500.0, 'W');
    t3.executeTransaction(myAccount);
    myAccount.showAccountDetails();
    cout << endl;

    return 0;
}
