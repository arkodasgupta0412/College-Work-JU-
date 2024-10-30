#include <iostream>
using namespace std;

class Array
{
    int *p;
    int size;

public:
    Array() : p(NULL), size(0) {}
    Array(int k, int x)
    {
        cout << "1st constructor called\n";
        size = k;
        if (k == 0)
            p = NULL;
        else
        {
            p = new int[size];
            for (int i = 0; i < size; i++)
            {
                p[i] = x;
            }
        }
    }

    Array(int k)
    {
        cout << "2nd constructor called\n";
        size = k;
        if (k == 0)
            p = NULL;
        else
        {
            p = new int[size];
            for (int i = 0; i < size; i++)
            {
                cin >> p[i];
            }
        }
    }

    Array(const Array &a)
    {
        cout << "3rd constructor called\n";
        size = a.size;
        if (size == 0)
            p = NULL;

        else
        {
            p = new int[size];
            for (int i = 0; i < size; i++)
            {
                p[i] = a.p[i];
            }
        }
    }

    Array(int arr[], int n)
    {
        cout << "4th constructor called\n";
        size = n;
        if (n == 0)
            p = NULL;
        else
        {
            p = new int[size];
            for (int i = 0; i < size; i++)
            {
                p[i] = arr[i];
            }
        }
    }

    Array operator+(const Array &a)
    {
        Array c(max(size, a.size), 0);
        int i = 0;
        while (i < size && i < a.size)
        {
            c.p[i] = p[i] + a.p[i];
            i++;
        }

        while (i < size)
        {
            c.p[i] = p[i];
            i++;
        }

        while (i < a.size)
        {
            c.p[i] = a.p[i];
            i++;
        }

        return c;
    }

    ~Array()
    {
        if (p != NULL)
            delete[] p;
    }

    friend ostream &operator<<(ostream &, const Array &);
};

ostream &operator<<(ostream &cout, const Array &a)
{
    for (int i = 0; i < a.size; i++)
    {
        cout << a.p[i] << " ";
    }
    return cout;
}

int main()
{
    Array a(5, 2);
    Array b(6, 9);
    Array c(a);

    int arr[7] = {8, 9, 3, 2, 10, 7, 5};
    Array d(arr, 7);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;

    Array e = a + b;
    cout << e << endl;
}