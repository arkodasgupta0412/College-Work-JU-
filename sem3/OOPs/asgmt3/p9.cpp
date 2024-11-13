#include <iostream>
#include <string.h>
#define MAX 20
using namespace std;

class Applicant
{
    static int last_id;
    int id;
    char name[MAX];
    int score;

public:
    Applicant(char name[], int score) : id(++last_id), score(score) { strcpy(this->name, name); }

    void show()
    {
        cout << "Applicant ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Score: " << score << endl;
    }

    static int getTotal()
    {
        return last_id;
    }
};

int Applicant::last_id = 0;

int main()
{
    // Create applicants
    Applicant applicant1("John Doe", 85.5);
    Applicant applicant2("Jane Smith", 90.0);
    Applicant applicant3("Alice Brown", 88.7);

    // Show applicant details
    cout << "Applicant 1 Details:\n";
    applicant1.show();
    cout << endl;

    cout << "Applicant 2 Details:\n";
    applicant2.show();
    cout << endl;

    cout << "Applicant 3 Details:\n";
    applicant3.show();
    cout << endl;

    // Get the number of applicants
    cout << "Total number of applicants: " << Applicant::getTotal() << endl;

    return 0;
}