#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Employee
{
protected:
    int id;
    string name;
    string desig;
    double basic_pay;

    // constructor
    Employee(int id, string name, string desig, double basic_pay)
        : id(id), name(name), desig(desig), basic_pay(basic_pay) {}

public:
    int getId() const
    {
        return id;
    }

    virtual double calcSalary(void) = 0;
};

class Permanent : public Employee
{
public:
    Permanent(int id, string name, string desig, double basic_pay) : Employee(id, name, desig, basic_pay) {}

    double calcSalary()
    {
        double hra = 0.3 * basic_pay;
        double da = 0.8 * basic_pay;

        double salary = basic_pay + hra + da;
        return salary;
    }
};

class Contractual : public Employee
{
    double allowance;

public:
    Contractual(int id, string name, string dept, double basic_pay, double allowance) : Employee(id, name, dept, basic_pay), allowance(allowance) {}

    double calcSalary()
    {
        double salary = basic_pay + allowance;
        return salary;
    }
};

class EmployeeList
{
    vector<Employee *> employees;

    int checkUnique(int id)
    {
        for (Employee *emp : employees)
        {
            if (emp->getId() == id)
            {
                return 0;
            }
        }
        return 1;
    }

public:
    void add()
    {
        int id;
        cout << "Enter employee ID: ";
        cin >> id;

        if (checkUnique(id))
        {
            int type;
            cout << "Enter employee type: Permanent(0) / Contractual(1): ";
            cin >> type;

            string name;
            string desig;
            double basic_pay;

            cout << "Name of employee: ";
            cin.ignore();
            getline(cin, name);
            cout << "Designation of employee: ";
            cin.ignore();
            getline(cin, desig);
            cout << "Enter basic pay: ";
            cin >> basic_pay;

            if (type == 0)
            {
                employees.push_back(new Permanent(id, name, desig, basic_pay));
            }
            else
            {
                double allowance;
                cout << "Enter allowance for contractual employee: ";
                cin >> allowance;
                employees.push_back(new Contractual(id, name, desig, basic_pay, allowance));
            }
        }

        else
        {
            cout << "EMPLOYEE ID NOT UNIQUE\n";
        }
    }

    void getSalary(int id)
    {
        for (Employee *emp : employees)
        {
            if (emp->getId() == id)
            {
                cout << "Salary: Rs " << emp->calcSalary() << endl;
                return;
            }
        }

        cout << "NO EMPLOYEE WITH THIS ID FOUND\n";
    }
};

class EmployeeManagementSystem
{
    EmployeeList list;

public:
    void menu()
    {
        bool running = true;
        while (running)
        {
            cout << "\nEmployee Management System:\n";
            cout << "1. Add Employee\n2. Salary of employee\n3. Exit\n";

            int ch;
            cout << "Enter choice: ";
            cin >> ch;

            switch (ch)
            {
            case 1:
                list.add();
                break;

            case 2:
            {
                int id;
                cout << "Employee Id: ";
                cin >> id;

                list.getSalary(id);
                break;
            }

            case 3:
                running = false;
                cout << "Thank You\n";
                break;

            case 4:
                cout << "Invalid choice\n";
                break;
            }
        }
    }
};

int main()
{
    EmployeeManagementSystem Google;
    Google.menu();
}