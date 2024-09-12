#include <iostream>
using namespace std;

void f(int x) {
	cout << "inside f(int)" << endl;
	cout << x << endl;
}

void f(float x) {
	cout << "inside f(float)" << endl;
	cout << x << endl;
}
	
int main() {
	
	int i = 3;
	float fl = 3.2;
	char c = '3';
	double d = 5.23;
	
	f(i);
	f(fl);
	f(c);
	f(d);
	
	return 0;
}
