#include <iostream>
#include <string>
using namespace std;

class Balance
{
    string account_number;
    double balance;
    string date_last_update;

public:
    Balance(string acc_num, double bal, string last_update)
        : account_number(acc_num), balance(bal), date_last_update(last_update) {}

    void updateBalance(double amount, string transaction_date, char transaction_type)
    {
        if (transaction_type == 'W')
        {
            if (balance >= amount)
            {
                balance -= amount;
                date_last_update = transaction_date;
                cout << "Withdrawal of Rs " << amount << ". Balance remaining: " << balance << endl;
            }
            else
            {
                cout << "Withdrawal of Rs " << amount << endl;
                cout << "Insufficient funds for withdrawal! Balance remaining: " << balance << endl;
            }
        }
        else if (transaction_type == 'D')
        {
            balance += amount;
            date_last_update = transaction_date;
            cout << "Deposit of Rs " << amount << ". Balance: " << balance << endl;
        }
    }

    void showAccountDetails() const
    {
        cout << "Account Number: " << account_number << endl;
        cout << "Balance: " << balance << endl;
        cout << "Last Update Date: " << date_last_update << endl;
    }

    // accessor function
    string getAccountNumber() const
    {
        return account_number;
    }
};

class Transaction
{
    string account_number;
    string date_of_transaction;
    double amount;
    char transaction_type; // 'W' for Withdrawal, 'D' for Deposit

public:
    Transaction(string acc_num, string trans_date, double amt, char trans_type)
        : account_number(acc_num), date_of_transaction(trans_date), amount(amt), transaction_type(trans_type) {}

    void executeTransaction(Balance &balance)
    {
        if (account_number == balance.getAccountNumber())
        {
            balance.updateBalance(amount, date_of_transaction, transaction_type);
        }
        else
        {
            cout << "Transaction failed! Account number mismatch." << endl;
        }
    }
};

int main()
{
    // Create a BALANCE object for the account
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

    // Show the final account details
    myAccount.showAccountDetails();

    return 0;
}
