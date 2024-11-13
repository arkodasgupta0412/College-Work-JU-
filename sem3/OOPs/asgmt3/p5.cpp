#include <iostream>
using namespace std;

void f(int x, int y) {
	cout << "Inside f(int, int)" << endl;
	cout << "x: " << x << ", y: "<< y << endl;
}

void f(char x, int y) {
	cout << "Inside f(char, int)" << endl;
	cout << "x: " << x << ", y: " << y << endl;
}

int main() {
	int i = 3;
	char ch = 'a';
	
	f(i, i);
	f(i, ch);
	f(ch, ch);

	f(4.5, 6.7);
	
	return 0;
}
