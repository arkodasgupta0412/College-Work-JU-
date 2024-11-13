#include <iostream>
#include <math.h>
using namespace std;

class Complex
{
    float r;
    float im;

public:
    /* constructors and some overloadings */
    Complex() : r(0), im(0) {}
    Complex(float x) : r(x), im(x) {}
    Complex(float x, float y) : r(x), im(y) {}

    // overloading the ostream reference 'cout'
    friend ostream &operator<<(ostream &, const Complex &);
    friend istream &operator>>(istream &, Complex &);

    float mod()
    {
        return sqrt(r * r + im * im);
    }

    Complex conjugate()
    {
        return Complex(r, -im);
    }

    Complex operator+(Complex &z)
    {
        return Complex(r + z.r, im + z.im);
    }

    Complex operator-(Complex &z)
    {
        return Complex(r - z.r, im - z.im);
    }

    Complex operator*(Complex &z)
    {
        return Complex((r * z.r - im * z.im), (r * z.im + im * z.r));
    }

    Complex operator/(Complex &z)
    {
        float m = z.mod();
        if (m != 0.0)
            return Complex((r * z.r + im * z.im) / (m * m), (im * z.r - r * z.im) / (m * m));

        cout << "Cannot divide by zero" << endl;
        return Complex();
    }
};

// overloaded cout for usage in Complex types
ostream &operator<<(ostream &os, const Complex &z)
{
    os << "(" << z.r << ")" << " + " << "(" << z.im << ")i";
    return os;
}

istream &operator>>(istream &is, Complex &z)
{
    is >> z.r;
    is >> z.im;
    return is;
}

int main()
{
    // Complex c1;
    // Complex c2(4, 3);
    // Complex c3(2);
    // Complex c4(9, 5);

    Complex c1, c2, c3, c4;
    cout << "Enter complex number c1: ";
    cin >> c1;
    cout << "Enter complex number c2: ";
    cin >> c2;
    cout << "Enter complex number c3: ";
    cin >> c3;
    cout << "Enter complex number c4: ";
    cin >> c4;

    // operations
    cout << c1 + c2 << endl;
    cout << (c3 - c4) << endl;
    cout << c2.conjugate() << endl;
    cout << c4.mod() << endl;
    cout << (c2 * c3) << endl;
    cout << (c2 / c4) << endl;
}
