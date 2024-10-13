#include <iostream>
#include <string>
using namespace std;

int ctoi(char);

class Time
{
	int h;
	int m;
	int s;

	/* used to verify if entered time is in 24 hour / 12 hours format */
	/* flag = 0 -> 24 hr, flag = 1 -> 12hr (PM), flag = 2 -> 12 hr (AM)*/
	int flag = 0;

	string edit(int t)
	{
		if (t < 10)
			return "0" + to_string(t);
		else
			return to_string(t);
	}

public:
	/* constructor overloading */
	Time(const char c[]) : h(ctoi(c[0]) * 10 + ctoi(c[1])), m(ctoi(c[3]) * 10 + ctoi(c[4])), s(ctoi(c[6]) * 10 + ctoi(c[7]))
	{
		if ((c[9] == 'P' || c[9] == 'p') && (h != 0 && h != 12))
			flag = 1;
		if (c[9] == 'A' || c[9] == 'a')
			flag = 2;
	}

	void display24hr()
	{
		if (!flag)
		{
			cout << edit(h) << ":" << edit(m) << ":" << edit(s) << endl;
		}
		else
		{
			int x = (h + 12) % 24;
			cout << edit(x) << ":" << edit(m) << ":" << edit(s) << endl;
		}
	}

	void displayAMPM()
	{
		if (flag == 1)
		{
			cout << edit(h) << ":" << edit(m) << ":" << edit(s) << " PM" << endl;
		}
		else if (flag == 2 || h <= 12)
		{
			cout << edit(h) << ":" << edit(m) << ":" << edit(s) << " AM" << endl;
		}
		else
		{
			cout << edit(h % 12) << ":" << edit(m) << ":" << edit(s) << " PM" << endl;
		}
	}

	void addMinutes(int min)
	{
		h = h + ((m + min) / 60);
		m = (m + min) % 60;
	}
};

int ctoi(char c)
{
	return c - '0';
}

int main()
{
	Time t1("13:34:21");
	t1.display24hr();

	t1.displayAMPM();

	t1.addMinutes(30);
	t1.display24hr();

	t1.displayAMPM();

	return 0;
}
