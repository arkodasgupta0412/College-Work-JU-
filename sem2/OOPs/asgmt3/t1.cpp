#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    int roll;
    char *name;
    int score;

public:
    Student(int r = -1)
    {
        roll = r;
        name = NULL;
        score = -1;
    }
    Student(int r, char *s, int sc)
    {
        roll = r;
        int l = strlen(s);
        name = new char[l + 1];
        strcpy(name, s);
        score = sc;
    }

    Student(const Student &s)
    {
        roll = s.roll;
        int l = strlen(s.name);
        name = new char[l + 1];
        strcpy(name, s.name);
        score = s.score;
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

    void releaseName()
    {
        free(name);
    }
};

int main()
{
    Student s1(1);
    Student s2(2, "abc", 75);
    Student s3(s2);

    cout << "Before update:\n";
    s2.display();
    s3.display();

    cout << "After update:\n";
    s2.updateName("def");
    s2.display();
    s3.display();

    s2.releaseName();
    cout << "After memory release:\n";
    s2.display();
    s3.display();
}