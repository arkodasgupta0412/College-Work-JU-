#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    int roll;
    char name[30];
    int score;

public:
    Student(int r = -1)
    {
        roll = r;
        name[30] = '\0';
        score = -1;
    }
    Student(int r, char *s, int sc)
    {
        roll = r;
        strcpy(name, s);
        score = sc;
    }

    void display()
    {
        cout << "roll: " << roll << endl;
        cout << "name: " << name << endl;
        cout << "score: " << score << endl;
    }

    void updateName(char *c)
    {
        strcpy(name, c);
    }
};

int main()
{
    Student s1(1);
    Student s2(2, "abc", 75);

    Student s3(s2);

    // s1.display();
    cout << "Before update:\n";
    s2.display();
    s3.display();

    cout << "After update:\n";
    s2.updateName("def");
    s2.display();
    s3.display();
}