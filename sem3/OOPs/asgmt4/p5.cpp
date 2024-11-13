#include <iostream>
using namespace std;

class String
{
    int *pcnt;
    char *arr;
    int size;

public:
    String(int s = 0, char e = '\0')
    {
        size = s;
        if (s == 0)
        {
            pcnt = NULL;
            arr = NULL;
        }

        else
        {
            arr = new char[s + 1];
            pcnt = new int(1);
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
        arr = a.arr;
        pcnt = a.pcnt;
        if (pcnt != NULL)
        {
            (*pcnt)++;
        }
    }

    String(char a[], int s)
    {
        size = s;
        if (s == 0)
            arr = NULL;
        arr = new char[s + 1];
        pcnt = new int(1);
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

    String &operator=(const String &a)
    {
        // Self-assignment check
        if (this == &a)
            return *this;

        // Decrement the reference count of current object
        if (pcnt != NULL)
        {
            (*pcnt)--;
            if (*pcnt == 0)
            {
                delete[] arr;
                delete pcnt;
            }
        }

        // Assign the new object's data
        arr = a.arr;
        pcnt = a.pcnt;
        size = a.size;
        if (pcnt != NULL)
        {
            (*pcnt)++;
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

    int getPcnt()
    {
        return *pcnt;
    }

    ~String()
    {
        if (pcnt != NULL)
        {
            *pcnt = *pcnt - 1;
            if (*pcnt == 0)
            {
                delete pcnt;
                delete[] arr;
            }
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
    cout << "a1 ref count: " << a1.getPcnt() << endl;

    String a2(6, 'b');
    cout << "a2 ref count: " << a2.getPcnt() << endl;

    String a3(a1);
    cout << "a1 ref count after a3 copy: " << a1.getPcnt() << endl;
    cout << "a3 ref count: " << a3.getPcnt() << endl;

    char arr[8] = "abcdefg";
    String a4(arr, 8);
    cout << "a4 ref count: " << a4.getPcnt() << endl;

    String a5 = a2 + a4;
    cout << "a5 ref count after concatenation: " << a5.getPcnt() << endl;

    String a6;
    a6 = a2;
    cout << "a6 ref count after assignment: " << a6.getPcnt() << endl;

    cout << a5[0] << " " << a5[8] << endl;

    int ans = a5 < a4;
    cout << "Comparison result: " << ans << endl;
}