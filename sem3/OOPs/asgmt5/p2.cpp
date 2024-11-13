#include <iostream>
#include <string>
#include <vector>
#define MAX_BOOKS 500
#define STU_ISSUE_LIMIT 2
#define FAC_ISSUE_LIMIT 10
using namespace std;

/* Foundation Class: Book */
class Book
{
    int id;
    int sno;
    string title;
    string author;
    string publisher;
    int price;

public:
    Book(int id, int sno, string title, string author, string publisher, int price) : id(id), sno(sno), title(title), author(author), publisher(publisher), price(price) {}

    int getId() const
    {
        return id;
    }
};

/* Foundation class: Member */
class Member
{
protected:
    int id;
    string name;
    string email;
    string address;
    int issue_limit;

    Member() {}
    Member(int id, string name, string email, string address) : id(id), name(name), email(email), address(address) {}

public:
    virtual void set_Issue_Limit() = 0;
};

/* Inherited Class: Student -> Member type */
class Student : public Member
{

public:
    Student(int id, string name, string email, string address) : Member(id, name, email, address) {}
    void set_Issue_Limit() { issue_limit = STU_ISSUE_LIMIT; }
};

/* Inherited Class: Faculty -> Member type */
class Faculty : public Member
{

public:
    Faculty(int id, string name, string email, string address) : Member(id, name, email, address) {}
    void set_Issue_Limit() { issue_limit = FAC_ISSUE_LIMIT; }
};

class BookList
{
    vector<Book> list;
    int checked(int id) const
    {
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i].getId() == id)
                return 0;
        }
        return 1;
    }

public:
    void addBook()
    {
        int id;
        cout << "Enter book id: ";
        cin >> id;
        if (checked(id))
        {
            int copy, price;
            string author, title, publisher;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter author name: ";
            cin >> author;
            cout << "Enter publisher name: ";
            cin >> publisher;
            cout << "Enter price: ";
            cin >> price;
            cout << "Enter number of copies: ";
            cin >> copy;
            for (int i = 1; i <= copy; i++)
            {
                list.push_back(Book(id, i, title, author, publisher, price));
            }
        }
        else
        {
            cout << "BOOK WITH SAME ID EXISTS!\n";
        }
    }
};

class Transaction
{
    int type;
    string status;

public:
    Transaction(int type) : type(type) {}

    void executeTransaction()
    {
        }
};

int main()
{
    return 0;
}