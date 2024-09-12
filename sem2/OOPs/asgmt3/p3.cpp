#include <iostream>
using namespace std;

double taxAmount(double income, double r = 10.0) {
	return income * (r / 100);
}

int main() {
	double income, r;
	
	cout << "Enter income: ";
	cin >> income;

	cout << "Enter rate: ";
	cin >> r;

	// not default argument
	cout << "Tax with user input rate: " << taxAmount(income, r) << endl;

	// default argument
	cout << "Tax with default rate: " << taxAmount(income) << endl;

	return 0;
}
