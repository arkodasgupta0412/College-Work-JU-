#include <iostream>
#include <string>
#include <vector>
#define MAX_SUBJ 5
#define MAX_STU 20
using namespace std;

class Subject
{
    int code;
    string name;

public:
    Subject() {}
    Subject(int code, string name) : code(code), name(name) {}

    string getName() const
    {
        return name;
    }
};

class Student
{
    int roll;
    string name;
    vector<Subject> list; // for this default constructor is required in subject class

public:
    Student() {}
    Student(int roll, string name) : roll(roll), name(name)
    {
        for (int i = 0; i < MAX_SUBJ; i++)
        {
            cout << "Enter details of subject " << i + 1 << ":\n";
            int code;
            string name;
            cout << "Enter subject code: ";
            cin >> code;
            cout << "Enter subject name: ";
            cin.ignore();
            getline(cin, name);

            list.push_back(Subject(code, name));
        }
    }

    int getRoll() const
    {
        return roll;
    }

    string getName() const
    {
        return name;
    }

    vector<Subject> getSubjects() const
    {
        return list;
    }

    void show(int roll)
    {
        cout << "Student Details:\n";
        cout << "Roll: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Subjects: " << endl;
        for (int i = 1; i <= MAX_SUBJ; i++)
        {
            cout << "Subject " << i << list[i - 1].getName() << endl;
        }
    }
};

class StudentList
{
    vector<Student> list;
    static int count;

    int checkUnique(int roll) const
    {
        for (int i = 0; i < count; i++)
        {
            if (list[i].getRoll() == roll)
            {
                return 0;
            }
        }
        return 1;
    }

    int search(int roll) const
    {
        for (int i = 0; i < count; i++)
        {
            if (list[i].getRoll() == roll)
            {
                return i;
            }
        }
        return -1;
    }

public:
    StudentList() {}

    void add()
    {
        int roll;
        cout << "Enter roll: ";
        cin >> roll;

        if (checkUnique(roll))
        {
            string name;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            count++;
            list.push_back(Student(roll, name));
            cout << "STUDENT RECORD ADDED!\n";
        }

        else
        {
            cout << "ROLL " << roll << " ALREADY EXISTS IN LIST!\n";
        }
    }

    void showSubjects(int roll) const
    {
        int k = search(roll);

        if (k == -1)
        {
            cout << "STUDENT WITH ROLL " << roll << " NOT FOUND!.\n";
            return;
        }

        vector<Subject> v = list[k].getSubjects();

        cout << "\nSUBJECTS OPTED BY ROLL " << roll << ":\n";
        for (int i = 0; i < MAX_SUBJ; i++)
        {
            cout << v[i].getName() << endl;
        }
    }

    void showStudents(string subName) const
    {
        cout << "\nSTUDENTS WHO HAVE OPTED FOR " << subName << ":\n";
        int cnt = 0, found = 0;
        for (int i = 0; i < count; i++)
        {
            vector<Subject> v = list[i].getSubjects();
            for (int j = 0; j < MAX_SUBJ; j++)
            {
                if (v[j].getName() == subName)
                {
                    found = 1;
                    cout << ++cnt << ". " << list[i].getName() << endl;
                }
            }
        }
        if (!found)
        {
            cout << "NO STUDENT OPTED FOR THIS SUBJECT\n";
        }
    }
};

int StudentList::count = 0;

class StudentManagementSystem
{
    StudentList studentlist;

public:
    StudentManagementSystem() {}

    void menu()
    {
        bool running = true;
        while (running)
        {
            cout << "\nStudent Management System Menu:\n";
            cout << "1. Add Student\n";
            cout << "2. Show Subjects by Roll\n";
            cout << "3. Show Students by Subject\n";
            cout << "4. Exit\n";

            cout << "Enter your choice: ";
            int choice;
            cin >> choice;

            switch (choice)
            {

            case 1:
                studentlist.add();
                break;

            case 2:
            {
                int roll;
                cout << "Enter roll of student: ";
                cin >> roll;
                studentlist.showSubjects(roll);
                break;
            }

            case 3:
            {
                string subName;
                cout << "Enter the subject name: ";
                cin.ignore();
                getline(cin, subName);
                studentlist.showStudents(subName);
                break;
            }

            case 4:
                running = false;
                cout << "Thank You\n";
                break;

            default:
                cout << "Invalid choice. Enter again\n";
            }
        }
    }
};

int main()
{
    StudentManagementSystem JU;
    JU.menu();
    return 0;
}
