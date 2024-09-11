#include <iostream>
using namespace std;

int& getMax(int &a, int &b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	int x, a, b;
	cout << "Enter the values of a and b: ";
	cin >> a >> b;
	
	x = getMax(a, b);
	
	int &y = getMax(a, b);
	
	cout << "The greater element (returning value): " << x << endl;
	cout << "The greater element (returning reference): " << y << endl;
	
	cout << "Enter new value of x to modify: ";
	cin >> x;
	
	cout << "Enter new value of y to modify: ";
	cin >> y;
	
	cout << "Value of x (returned value), a and b are: " << x << " " << a << " " << b << endl;	
	cout << "Value of y (returned reference), a, and b are: " << y << " " << a << " " << b << endl;
	
	return 0;
}
