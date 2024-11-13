#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    static int studentCount;
    int roll;
    string name;
    string course;
    string admissionDate;
    int marks[5];
    bool marksReceived;

public:
    Student(int r, string n, string c, string admDate) : roll(r), name(n), course(c), admissionDate(admDate), marksReceived(false)
    {
        studentCount++;
    }

    // Method to receive marks
    void receiveMarks(int m[])
    {
        for (int i = 0; i < 5; i++)
        {
            marks[i] = m[i];
        }
        marksReceived = true;
    }

    // Method to prepare and display the marksheet
    void prepareMarkSheet() const
    {
        cout << "Mark Sheet for Student Roll No: " << roll << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
        cout << "Admission Date: " << admissionDate << endl;

        if (marksReceived)
        {
            int total = 0;
            cout << "Marks in 5 subjects: ";
            for (int i = 0; i < 5; i++)
            {
                cout << marks[i] << " ";
                total += marks[i];
            }
            cout << endl;
            cout << "Total Marks: " << total << endl;
            cout << "Average Marks: " << total / 5.0 << endl;
        }
        else
        {
            cout << "Marks not received yet." << endl;
        }
    }

    static int getStudentCount()
    {
        return studentCount;
    }
};

// Initialize static variable
int Student::studentCount = 0;

int main()
{
    // Admission of students
    Student student1(101, "Alice", "Computer Science", "2024-09-01");
    Student student2(102, "Bob", "Mathematics", "2024-09-05");

    // Display the number of students after admission
    cout << "Total number of students who have taken admission: " << Student::getStudentCount() << endl;

    // Receive marks for student 1
    int marks1[] = {85, 90, 78, 92, 88};
    student1.receiveMarks(marks1);

    // Prepare and display mark sheet for both students
    student1.prepareMarkSheet();
    student2.prepareMarkSheet(); // No marks received for student 2

    return 0;
}
