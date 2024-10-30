#include <iostream>
using namespace std;

class String
{
    char* arr;
    char _size;

public:
    String() : arr(NULL), _size(0) {}
    String(int len, int ele)
    {
        cout << "1st constructor called\n";
        _size = len;
        if (len == 0)
            arr = NULL;
        else
        {
            arr = new char[_size];
            for (int i = 0; i < _size; i++)
            {
                arr[i] = ele;
            }
        }
    }

    String(int len)
    {
        cout << "2nd constructor called\n";
        _size = len;
        if (len == 0)
            arr = NULL;
        else
        {
            arr = new char[_size];
            for (int i = 0; i < _size; i++)
            {
                cin >> arr[i];
            }
        }
    }

    String(const String &a)
    {
        // cout << "3rd constructor called\n";
        _size = a._size;
        if (_size == 0)
            arr = NULL;

        else
        {
            arr = new char[_size];
            for (int i = 0; i < _size; i++)
            {
                arr[i] = a.arr[i];
            }
        }
    }

    String(char p[], int n)
    {
        // cout << "4th constructor called\n";
        _size = n;
        if (n == 0)
            arr = NULL;
        else
        {
            arr = new char[_size];
            for (int i = 0; i < _size; i++)
            {
                arr[i] = arr[i];
            }
        }
    }

    String operator+(const String &s)
    {
        String c(_size + s._size);
        int i = 0, j = 0;
        while (i < _size)
        {
            c.arr[i++] = arr[i++];
        }

        while (j < s._size)
        {
            c.arr[i++] = arr[j++];
        }

        return c;
    }

    String& operator=(const String& a) {
	String c(a._size, 0);
	if (this != &a) {
		for (int i = 0; i < a._size; i++) {
			this->arr[i] = a.arr[i];
		}
	}
	return *this;
    }

    int operator[](int i) {
	return arr[i];
    }

    ~String()
    {
        if (arr != NULL)
            delete[] arr;
    }

    friend ostream &operator<<(ostream&, const String&);
};

ostream &operator<<(ostream &cout, const String& a)
{
    for (int i = 0; i < a._size; i++)
    {
        cout << a.arr[i];
    }
    return cout;
}

int main() {
	String s(4, 'c');
	cout << s << endl;

	char x[8] = "Lombrata";
	String s1(8, x);
	cout << s + s1 << endl;
	
}
