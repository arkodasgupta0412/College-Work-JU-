#include <iostream>
using namespace std;

class Complex
{
    int r, im;

public:
    Complex(int a = 0, int b = 0)
    {
        r = a;
        im = b;
    }

    Complex operator+(Complex c)
    {
        return Complex(r + c.r, im + c.im);
    }

    Complex operator*(Complex c)
    {
        return Complex(r * c.r - im * c.im, r * c.im + im * c.r);
    }

    Complex operator*(int k)
    {
        return Complex(r * k, im * k);
    }

    friend ostream &operator<<(ostream &, Complex);
    friend Complex operator*(int, Complex);
};

ostream &operator<<(ostream &cout, Complex c)
{
    cout << "(" << c.r << ")" << " + (" << c.im << ")i";
}

Complex operator*(int k, Complex c)
{
    return Complex(k * c.r, k * c.im);
}

int main()
{
    Complex c1(5, 2);
    cout << c1 << endl;
    Complex c2(3, 4);
    cout << c2 << endl;
    int k = 4;

    cout << c1 + c2 << endl;
    cout << c1 * c2 << endl;
    cout << c1 * k << endl;
    cout << k * c1 << endl;
}