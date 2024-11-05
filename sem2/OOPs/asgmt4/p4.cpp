#include <iostream>
using namespace std;

class String
{
    char *arr;
    int size;

public:
    String(int s = 0, char e = '\0')
    {
        size = s;
        if (s == 0)
        {
            arr = NULL;
        }

        else
        {
            arr = new char[s + 1];
            for (int i = 0; i < size; i++)
            {
                arr[i] = e;
            }
            arr[size] = '\0';
        }
    }

    String(const String &a)
    {
        size = a.size;
        if (size != 0)
        {
            arr = new char[size + 1];
            for (int i = 0; i < size; i++)
            {
                arr[i] = a.arr[i];
            }
            arr[size] = '\0';
        }
        else
        {
            arr = NULL;
        }
    }

    String(char a[], int s)
    {
        size = s;
        if (s == 0)
            arr = NULL;
        arr = new char[s + 1];
        for (int i = 0; i < size; i++)
        {
            arr[i] = a[i];
        }
        arr[size] = '\0';
    }

    String operator+(const String &a)
    {
        String res(size + a.size + 1);
        int i = 0, j = 0;
        while (i < size)
        {
            res.arr[i] = arr[i];
            i++;
        }

        while (j < a.size)
        {
            res.arr[i] = a.arr[j];
            i++, j++;
        }

        res.arr[i] = '\0';
        return res;
    }

    String operator=(const String &a)
    {
        size = a.size;
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] = a.arr[i];
            }
        }
        else
        {
            arr = NULL;
        }

        return *this;
    }

    char &operator[](int i)
    {
        return arr[i];
    }

    int operator<(const String &a)
    {
        if (size < a.size)
        {
            return 1;
        }

        if (size == a.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i] < a.arr[i])
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    int operator>(const String &a)
    {
        if (size > a.size)
        {
            return 1;
        }

        if (size == a.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (arr[i] > a.arr[i])
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    ~String()
    {
        if (arr != NULL)
        {
            delete[] arr;
        }
    }

    friend String operator*(int, const String);
    friend ostream &operator<<(ostream &, const String &);
};

ostream &operator<<(ostream &cout, const String &a)
{
    for (int i = 0; i < a.size; i++)
    {
        cout << a.arr[i];
    }
    cout << endl;
    return cout;
}

int main()
{
    String a1(5);
    String a2(6, 'b');
    String a3(a1);
    char arr[8] = "abcdefg";
    char arr1[8] = "abcdefh";
    String a4(arr, 8);

    cout << a2 << a4;

    String a5 = a2 + a4;
    cout << a5;

    String a6;
    a6 = a2;
    cout << a6;

    String a7(arr1, 8);

    cout << a5[0] << " " << a5[8] << endl;

    int ans = a5 < a4;
    cout << ans;
}