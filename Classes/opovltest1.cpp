#include <iostream>

using namespace std;

/*************************************************/

class Interval
{
public:
	Interval(long m, short s)
	{
		minutes = m + s / 60;
		seconds = s % 60;		
	}

	void Print() const
	{
		cout << minutes << ':' << seconds << endl;
	}

	long Period() const
	{
		return 60 * minutes + seconds;
	}

	Interval operator+(const Interval& other) const
	{
		return Interval(minutes + other.minutes, 
			seconds + other.seconds);
	}

	Interval operator+(long value) const
	{
		return Interval(minutes, seconds + value);
	}

	Interval operator++()
	{
		seconds += 1;

		if(seconds == 60)
			seconds = 0, minutes += 1;

		return Interval(minutes, seconds);
	}

	Interval operator++(int)
	{
		Interval old(minutes, seconds);

		seconds += 1;

		if(seconds == 60)
			seconds = 0, minutes += 1;

		return old;
	}

private:
	long minutes;
	short seconds;
	
friend Interval operator+(long, const Interval&);
};

Interval operator+(long value, const Interval& rhs)
{
	return Interval(rhs.minutes, rhs.seconds + value);
}

/*************************************************/

Interval operator-(const Interval& lhs, const Interval& rhs)
{
	return Interval(0, lhs.Period() - rhs.Period());
}

int main(void)
{
	Interval a(7, 30);
	a.Print();

	Interval b(2, 105);
	b.Print();
	
	Interval c = a + b; //a.operator+(b)
	c.Print();

	Interval d = a - b; //operator-(a, b)
	d.Print();

	Interval e = d + 5; //d.operator+(5)
	e.Print();

	Interval f = 15 + e; //operator+(15, e)
	f.Print();

	Interval g = ++f; //f.operator++()
	f.Print();
	g.Print();

	Interval h = g++; //g.operator++(0)
	g.Print();
	h.Print();
}



















