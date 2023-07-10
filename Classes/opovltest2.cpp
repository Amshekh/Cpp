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

	long operator[](int index) const
	{
		if(index == 0)
			return seconds;
		return minutes;
	}

	long operator()(int index) const
	{
		if(index == 0)
			return seconds;
		return minutes;
	}

	//Conversion constructor
	Interval(double value)
	{
		minutes = long(value);
		seconds = short(60 * (value - minutes));
	}

	operator double() const
	{
		return minutes + seconds / 60.0;
	}

private:
	long minutes;
	short seconds;
	
};


/*************************************************/


int main(void)
{
	Interval a(5, 75);
	a.Print();
	cout << a[1] << " minutes and " << a(0) << " seconds." << endl;

	Interval b = 3.25; //Interval b(3.25);
	b.Print();

	double c = b;
	cout << c << endl;
}


















