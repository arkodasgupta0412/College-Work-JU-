#include <iostream>
using namespace std;

class Array
{
    int* p;
    int _size;

public:
    Array() : p(NULL), _size(0) {}
    Array(int k, int x)
    {
        // cout << "1st constructor called\n";
        _size = k;
        if (k == 0)
            p = NULL;
        else
        {
            p = new int[_size];
            for (int i = 0; i < _size; i++)
            {
                p[i] = x;
            }
        }
    }

    Array(int k)
    {
        // cout << "2nd constructor called\n";
        _size = k;
        if (k == 0)
            p = NULL;
        else
        {
            p = new int[_size];
            for (int i = 0; i < _size; i++)
            {
                cin >> p[i];
            }
        }
    }

    Array(const Array &a)
    {
        // cout << "3rd constructor called\n";
        _size = a._size;
        if (_size == 0)
            p = NULL;

        else
        {
            p = new int[_size];
            for (int i = 0; i < _size; i++)
            {
                p[i] = a.p[i];
            }
        }
    }

    Array(int arr[], int n)
    {
        // cout << "4th constructor called\n";
        _size = n;
        if (n == 0)
            p = NULL;
        else
        {
            p = new int[_size];
            for (int i = 0; i < _size; i++)
            {
                p[i] = arr[i];
            }
        }
    }

    int getSize() {
	return this->_size;
    }

    int* getArr() {
	return this->p;
    }

    Array operator+(const Array &a)
    {
        Array c(max(_size, a._size), 0);
        int i = 0;
        while (i < _size && i < a._size)
        {
            c.p[i] = p[i] + a.p[i];
            i++;
        }

        while (i < _size)
        {
            c.p[i] = p[i];
            i++;
        }

        while (i < a._size)
        {
            c.p[i] = a.p[i];
            i++;
        }

        return c;
    }

    Array& operator=(const Array& a) {
	Array c(a._size, 0);
	if (this != &a) {
		for (int i = 0; i < a._size; i++) {
			this->p[i] = a.p[i];
		}
	}
	return *this;
    }

    int operator[](int i) {
	return p[i];
    }

    Array& operator*(int scalar) {
	for (int i = 0; i < this->_size; i++) {
		this->p[i] *= scalar;
	}
	return (*this);
    }

    ~Array()
    {
        if (p != NULL)
            delete[] p;
    }

    friend ostream &operator<<(ostream&, const Array&);
};

ostream &operator<<(ostream &cout, const Array& a)
{
    for (int i = 0; i < a._size; i++)
    {
        cout << a.p[i] << " ";
    }
    return cout;
}

Array operator*(int scalar, Array& arr) {
    Array result(arr.getSize());

    for (int i = 0; i < arr.getSize(); i++) {
	result.getArr[i] = scalar * arr.getArr[i];
    }

    return result;
}

/* Array operator*(int scalar, const Array& a) {
	Array result(a.getSize());
	for (int i = 0; i < a._size; i++) {
		(result.p)[i] = scalar * (a.p)[i];
	}
	return result;
} */

int main()
{
    Array a(5, 2);
    Array b(6, 3);
    cout << a << endl;

    cout << a[2] << endl;
    cout << a[4] << endl;

    Array d = a * 3;
    cout << d << endl;

    Array c = 5 * b;
    cout << c << endl;
}
