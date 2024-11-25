#include <iostream>
#include <string>
#include <vector>
#define STU_ISSUE_LIMIT 2
#define FAC_ISSUE_LIMIT 10

class Book;
class Member;
class Student;
class Faculty;
class BookList;
class MemberList;
class Transaction;
class TransactionLog;

enum Status
{
    PENDING,
    RETURNED
};

int generateTransactionId()
{
    static int id = 100;
    return id++;
}

class Book
{
    int b_id;
    int sno;
    int copy;
    std::string title;
    std::string author;
    std::string publisher;
    double price;

public:
    Book(int b_id, std::string title, std::string author, std::string publisher, double price, int sno, int copy)
        : b_id(b_id), title(title), author(author), publisher(publisher), price(price), sno(sno), copy(copy) {}

    int get_bookId() const
    {
        return b_id;
    }
    int get_copy() const
    {
        return copy;
    }
    int get_sno() const
    {
        return sno;
    }
    void set_copy(int x) { copy += x; }

    void show() const
    {
        std::cout << b_id << "\t" << title << "\t" << author << "\t" << publisher << "\t" << price << "\t" << sno << "\t" << copy << std::endl;
    }
};

class Member
{
protected:
    int m_id;
    std::string name;
    std::string email;
    std::string address;
    int type;
    int issues;

public:
    Member() { issues = 0; }
    Member(int m_id, const std::string name, const std::string email, const std::string address, int type)
        : m_id(m_id), name(name), email(email), address(address), type(type) {}

    virtual ~Member() = default;
    virtual bool checkIssueLimit(int) const = 0;
    void show(int);
    int get_memberId() const { return m_id; }
    int get_issues() const { return issues; }
    int get_type() const { return type; }
    void set_issue(int x) { issues += x; }
};

class Student : public Member
{
public:
    Student(int id, const std::string name, const std::string email, const std::string address, int type)
        : Member(id, name, email, address, type) {}

    bool checkIssueLimit(int issues) const override
    {
        return issues < STU_ISSUE_LIMIT;
    }
};

class Faculty : public Member
{
public:
    Faculty(int id, const std::string name, const std::string email, const std::string address, int type)
        : Member(id, name, email, address, type) {}

    bool checkIssueLimit(int issues) const override
    {
        return issues < FAC_ISSUE_LIMIT;
    }
};

class BookList
{
    std::vector<Book> blist;
    int uniqueBookCheck(int);

public:
    int searchBook(int);
    void addBook(void);
    void showBooks(void);
    friend class Transaction;
};

class MemberList
{
    std::vector<Member *> mlist;
    int uniqueMemberCheck(int);

public:
    int searchMember(int);
    void addMember(void);
    void showMembers(void);
    /* std::vector<Member *> getList(void)
    {
       return mlist;
    } */
    friend class Transaction;
};

class Transaction
{
    int t_id;
    int m_id;
    int b_id;
    int sno;
    int type;
    Status status;
    std::string date;

public:
    Transaction() {}
    Transaction(int m_id, int b_id, int sno, int type, Status status) : date(date), t_id(generateTransactionId()), m_id(m_id), b_id(b_id), sno(sno), type(type), status(status) {}
    bool operator==(Transaction &t)
    {
        if (m_id == t.m_id && b_id == t.b_id && sno == t.sno && type == t.type && status == t.status)
            return 1;
        else
            return 0;
    }
    Transaction generateTransactionSlip(BookList &, MemberList &);
    void performTransaction(BookList &, MemberList &, TransactionLog &);
    void showTransactionDetail(Transaction &);
    int get_memberId() const { return m_id; }
    void set_status(Status s) { status = s; }
};

class TransactionLog
{
    std::vector<Transaction> log;
    int searchLog(int);

public:
    void addLog(Transaction &t) { log.push_back(t); }
    void updateLog(Transaction &t);
    void showTransaction(int);
};

/*                                      FUNCTION IMPLEMENTATIONS                                               */
void Member::show(int type)
{
    std::cout << m_id << "\t" << name << "\t" << email << "\t" << address << "\t";
    if (!type)
    {
        std::cout << issues << "\t" << STU_ISSUE_LIMIT << "\t" << "student\n";
    }
    else
    {
        std::cout << issues << "\t" << FAC_ISSUE_LIMIT << "\t" << "faculty\n";
    }
}

int BookList::uniqueBookCheck(int id)
{
    for (int i = 0; i < blist.size(); i++)
    {
        if (blist[i].get_bookId() == id)
        {
            return 0;
        }
    }
    return 1;
}

int BookList::searchBook(int id)
{
    for (int i = 0; i < blist.size(); i++)
    {
        if (blist[i].get_bookId() == id)
        {
            return i;
        }
    }
    return -1;
}

void BookList::addBook()
{
    int b_id, copy;
    std::string title, author, publisher;
    double price;

    std::cout << "Enter book id: ";
    std::cin >> b_id;
    std::cout << "Enter title: ";
    std::cin >> title;
    std::cout << "Enter author: ";
    std::cin >> author;
    std::cout << "Enter publisher: ";
    std::cin >> publisher;
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cout << "Enter number of copies: ";
    std::cin >> copy;

    if (uniqueBookCheck(b_id))
    {
        for (int i = 1; i <= copy; i++)
        {
            blist.push_back(Book(b_id, title, author, publisher, price, i, copy));
        }
    }
    else
        std::cout << "Book Id already exists!\n";
}

void BookList::showBooks()
{
    std::cout << "Book Id\tTitle\tAuthor\tPublisher\tPrice\tSno\tCopy\n";
    for (int i = 0; i < blist.size(); i++)
    {
        blist[i].show();
    }
}

int MemberList::uniqueMemberCheck(int id)
{
    for (int i = 0; i < mlist.size(); i++)
    {
        if (mlist[i]->get_memberId() == id)
        {
            return 0;
        }
    }
    return 1;
}

int MemberList::searchMember(int id)
{
    for (int i = 0; i < mlist.size(); i++)
    {
        if (mlist[i]->get_memberId() == id)
        {
            return i;
        }
    }
    return -1;
}

void MemberList::addMember()
{
    int m_id, type;
    std::string name, email, address;

    std::cout << "Enter member id: ";
    std::cin >> m_id;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter address: ";
    std::cin >> address;
    std::cout << "Student(0) / Faculty(1) ? ";
    std::cin >> type;

    if (uniqueMemberCheck(m_id))
    {
        if (type == 0)
            mlist.push_back(new Student(m_id, name, email, address, 0));
        else
            mlist.push_back(new Faculty(m_id, name, email, address, 1));
    }
    else
        std::cout << "Member Id already exists!\n";
}

void MemberList::showMembers()
{
    std::cout << "Member Id\tName\tEmail\tAddress\tIssues\tLimit\tType\n";
    for (int i = 0; i < mlist.size(); i++)
    {
        mlist[i]->show(mlist[i]->get_type());
    }
}

Transaction Transaction::generateTransactionSlip(BookList &book_rec, MemberList &member_rec)
{
    int m_id, b_id, type;
    Transaction invalid(0, 0, 0, 0, RETURNED);

    std::cout << "Enter member Id: ";
    std::cin >> m_id;

    int mIdx = member_rec.searchMember(m_id);

    if (mIdx != -1)
    {
        std::cout << "Enter 0 for issue, 1 for return: ";
        std::cin >> type;

        Member *member = member_rec.mlist[mIdx];

        if (!type)
        {
            if (!member->checkIssueLimit(member->get_issues()))
            {
                std::cout << "Issue limit reached. Please return pending books first.\n";
                return invalid;
            }

            std::cout << "Enter book id: ";
            std::cin >> b_id;

            int bIdx = book_rec.searchBook(b_id);

            if (bIdx != -1)
            {
                Book &book = book_rec.blist[bIdx];
                if (book.get_copy() <= 0)
                {
                    std::cout << "No copies available for this book.\n";
                    return invalid;
                }

                std::cout << "Transaction slip generated for issuing book.\n";
                return Transaction(m_id, b_id, book.get_sno(), type, PENDING);
            }

            else
            {
                std::cout << "Invalid book ID. Please check the book list.\n";
                return invalid;
            }
        }

        else if (type == 1)
        {
            std::cout << "Enter book Id and serial number: ";
            std::cin >> b_id >> sno;

            int bIdx = book_rec.searchBook(b_id);
            if (bIdx == -1)
            {
                std::cout << "Invalid book ID. Please check the book list.\n";
                return invalid;
            }

            std::cout << "Transaction slip generated for returning book.\n";
            return Transaction(m_id, b_id, sno, type, RETURNED);
        }
    }

    else
    {
        std::cout << "Invalid member ID. Please register first.\n";
        return invalid;
    }
}

void Transaction::performTransaction(BookList &book_rec, MemberList &member_rec, TransactionLog &log)
{
    Transaction invalid(0, 0, 0, 0, RETURNED);

    Transaction slip = generateTransactionSlip(book_rec, member_rec);
    if (slip == invalid)
    {
        std::cout << "Transaction slip has not been generated due to some error\n";
        return;
    }

    int mIdx = member_rec.searchMember(slip.m_id);
    int bIdx = book_rec.searchBook(slip.b_id);

    Member *member = member_rec.mlist[mIdx];
    Book &book = book_rec.blist[bIdx];

    if (slip.type == 0)
    {
        member->set_issue(1);
        book.set_copy(-1);
        std::cout << "Book issued successfully.\n";
        log.addLog(slip);
    }

    else
    {
        member->set_issue(-1);
        book.set_copy(1);
        std::cout << "Book returned successfully.\n";
        log.updateLog(slip);
    }
}

int TransactionLog::searchLog(int m_id)
{
    for (int i = 0; i < log.size(); i++)
    {
        if (log[i].get_memberId() == m_id)
            return i;
    }
    return -1;
}

void TransactionLog::updateLog(Transaction &t)
{
    int k = searchLog(t.get_memberId());
    log[k].set_status(RETURNED);
}

int main()
{
    BookList brec;
    MemberList mrec;
    TransactionLog log;

    int choice;

    while (true)
    {
        std::cout << "\n========================= Library Management System =========================\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Add Member\n";
        std::cout << "3. Issue Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "5. Show Books\n";
        std::cout << "6. Show Members\n";
        std::cout << "7. Exit\n";
        std::cout << "================================================================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            brec.addBook();
            break;

        case 2:
            mrec.addMember();
            break;

        case 3:
        {
            std::cout << "Issuing a book...\n";
            Transaction t;
            t.performTransaction(brec, mrec, log);
            break;
        }

        case 4:
        {
            std::cout << "Returning a book...\n";
            Transaction t;
            t.performTransaction(brec, mrec, log);
            break;
        }

        case 5:
            std::cout << "\n========================= List of Books =========================\n";
            brec.showBooks();
            break;

        case 6:
            std::cout << "\n========================= List of Members =========================\n";
            mrec.showMembers();
            break;

        case 7:
            std::cout << "\nExiting the system. Thank you for using the Library Management System!\n";
            return 0;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }
    }

    return 0;
}
