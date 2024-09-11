#include <iostream>
#define MAXLEN 31
using namespace std;

typedef struct student{
	int roll;
	char name[MAXLEN];	
	void getData(void) {
		cout << "Enter roll of student: ";
		cin >> roll;
		cout << "Enter name of student: ";
		cin >> name;
	}
	void showData(void) {
		cout << "Details of Students" << endl;
		cout << "Roll\t\t\tName" << endl;
		cout << roll << "\t\t\t" << name << endl;
	}
}student;

student& modifyData(student& s) {
	int ch;
	cout << "Which data to modify (1/2)?" << endl;
	cin >> ch;
	
	if (ch == 1) {
		cout << "Enter new roll: ";
		cin >> s.roll;
	}
	else {
		cout << "Enter new name: ";
		cin >> s.name;
	}
	
	return s;		
}

void showData(student& s) {
	cout << "Details of Students" << endl;
	cout << "Roll\t\t\tName" << endl;
	cout << s.roll << "\t\t\t" << s.name << endl;
}

int main() {
	student s;
	s.getData();
	s.showData();
	
	int running = 1;
	
	char c;
	
	while(running) {
		cout << "Do you want to modify the data? ";
		cin >> c;
	
		if (c == 'Y' || c == 'y') {
			s = modifyData(s);
			s.showData();
		}
		else {
			cout << "Quit" << endl;
			running = 0;
		}
	}
	
	
	return 0;
}
