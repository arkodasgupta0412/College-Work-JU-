#include <iostream>
using namespace std;

void swap(int a, int b) {
	int t = a;
	a = b;
	b = t;
	cout << "Values after swap: a = " << a << " b = " << b << endl;
}

int main() {
	int a, b;
	cout << "Enter two values: ";
	cin >> a >> b;

	cout << "Values before swap: a = " << a << " b = " << b << endl;

	swap(a, b);

	return 0;
}

