#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cricketer
{
protected:
    string name;
    string date_of_birth;
    int matches;

    // constructors
    Cricketer() {}
    Cricketer(string s, string dob, int m) : name(s), date_of_birth(dob), matches(m) {}

public:
    string getName() const { return name; }
    virtual void display() = 0;
};

class Batsman : virtual public Cricketer
{
    int total_runs;
    int avg_runs;

public:
    Batsman(string s, string dob, int m, int tr) : Cricketer(s, dob, m), total_runs(tr), avg_runs(tr / m) {}

    int getTotalRuns() const { return total_runs; }
    int getAvgRuns() const { return avg_runs; }

    void display() override
    {
        cout << "\nInfo:\n";
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << date_of_birth << endl;
        cout << "Number of matches played: " << matches << endl;
        cout << "Total runs: " << total_runs << endl;
        cout << "Average runs: " << avg_runs << endl;
    }
};

class Bowler : virtual public Cricketer
{
    int wickets;
    double avg_econ;

public:
    Bowler(string s, string dob, int m, int w) : Cricketer(s, dob, m), wickets(w), avg_econ((double)w / (double)m) {}

    int getWickets() const { return wickets; }
    double getAvgEcon() const { return avg_econ; }

    void display() override
    {
        cout << "\nInfo:\n";
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << date_of_birth << endl;
        cout << "Number of matches played: " << matches << endl;
        cout << "Total wickets: " << wickets << endl;
        cout << "Average economy: " << avg_econ << endl;
    }
};

class AllRounder : public Batsman, public Bowler
{
public:
    AllRounder(string s, string dob, int m, int tr, int w) : Cricketer(s, dob, m), Batsman(s, dob, m, tr), Bowler(s, dob, m, w) {}

    void display() override
    {
        cout << "\nInfo:\n";
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << date_of_birth << endl;
        cout << "Number of matches played: " << matches << endl;
        cout << "Total runs: " << getTotalRuns() << endl;
        cout << "Average runs: " << getAvgRuns() << endl;
        cout << "Total wickets: " << getWickets() << endl;
        cout << "Average economy: " << getAvgEcon() << endl;
    }
};

class DW_Pair
{
    pair<Batsman, Bowler> p;

public:
    DW_Pair(string s1, string dob1, int m1, string s2, string dob2, int m2, int tr, int ar, int w, double e) : p(Batsman(s1, dob1, m1, tr), Bowler(s2, dob2, m2, w)) {}
};

class Team
{
    vector<Cricketer *> team;

public:
    void addPlayer()
    {
        int type;
        cout << "Enter type of cricket player: Batsman(0), Bowler(1), All Rounder(2)\n";
        cin >> type;

        string name;
        string date_of_birth;
        int matches;

        cout << "\nEnter name of player: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter date of birth of player: ";
        cin.ignore();
        getline(cin, date_of_birth);
        cout << "Enter number of matches played: ";
        cin >> matches;

        if (type == 0)
        {
            int total_runs;
            cout << "Enter total runs scored: ";
            cin >> total_runs;
            team.push_back(new Batsman(name, date_of_birth, matches, total_runs));
        }

        else if (type == 1)
        {
            int wickets;
            cout << "Enter total wickets taken: ";
            cin >> wickets;

            team.push_back(new Bowler(name, date_of_birth, matches, wickets));
        }
        else
        {
            int total_runs, avg_runs, wickets;
            double avg_econ;
            cout << "Enter total runs scored: ";
            cin >> total_runs;
            cout << "Enter total wickets taken: ";
            cin >> wickets;
            team.push_back(new AllRounder(name, date_of_birth, matches, total_runs, wickets));
        }
    }

    void showInfo(string name)
    {
        for (Cricketer *c : team)
        {
            if (c->getName() == name)
            {
                c->display();
            }
        }
    }
};

class TeamManagement
{
    Team t;

public:
    void menu()
    {
        bool running = true;
        while (running)
        {
            cout << "\nWelcome to Team Management:\n";
            cout << "1. Add Player\n2. Show Info\n3. Exit\n";

            int ch;
            cout << "Enter choice: ";
            cin >> ch;

            switch (ch)
            {

            case 1:
                t.addPlayer();
                break;

            case 2:
            {
                string name;
                cout << "Enter name of player: ";
                cin.ignore();
                getline(cin, name);
                t.showInfo(name);
                break;
            }

            case 3:
                running = false;
                cout << "Thank You\n";
                break;

            default:
                cout << "Invalid choice. Enter again\n";
                break;
            }
        }
    }
};

int main()
{
    TeamManagement India;
    India.menu();
}