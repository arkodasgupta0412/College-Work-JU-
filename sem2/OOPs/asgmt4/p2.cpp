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
    friend ostream &operator<<(ostream &os, const Complex &z);

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
    if (z.im < 0)
        os << z.r << " + " << "(" << z.im << ")i" << endl;

    else
        os << z.r << " + " << z.im << "i" << endl;
}

int main()
{
    Complex c1;
    Complex c2(4, 3);
    Complex c3(2);
    Complex c4(9, 5);

    // operations
    cout << c1 + c2;
    cout << (c3 - c4);
    cout << c2.conjugate();
    cout << c4.mod() << endl;
    cout << (c2 * c3);
    cout << (c2 / c4);
}
