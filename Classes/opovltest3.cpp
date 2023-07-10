#include <iostream>

using namespace std;

/*************************************************/

class Interval
{
public:
	Interval(long m=0, short s=0)
	{
		minutes = m + s / 60;
		seconds = s % 60;
		cout << "-- Interval instance created." << endl;
	}

	//Copy constructor
	Interval(const Interval& original)
	{
		minutes = original.minutes;
		seconds = original.seconds;
		cout << "-- Interval instance copy created." << endl;	
	}

	Interval& operator=(const Interval& other)
	{
		if(this != &other)
		{
			minutes = other.minutes;
			seconds = other.seconds;
			cout << "-- Interval instance assigned." << endl;
		}
		
		return *this;
	}

	~Interval()
	{
		cout << "-- Interval instance destroyed." << endl;	
	}

	void Print() const
	{
		cout << minutes << ':' << seconds << endl;
	}

	long Period() const
	{
		return 60 * minutes + seconds;
	}


private:
	long minutes;
	short seconds;
	
};

/*************************************************/

class Journey
{
public:
	Journey(long d, const Interval& t) : time(t)
	{
		distance = d;
		//time = t;
		cout << "-- Journey instance created." << endl;
	}

	/*
	long Period() const
	{
		return time.Period();
	}
	*/

	Interval* operator->()
	{
		return &time;
	}

	~Journey()
	{
		cout << "-- Journey instance destroyed." << endl;
	}
private:
	long distance;
	Interval time;
};

int main(void)
{
	Interval a(6, 15);
	/*
	Interval b = a; //Interval b(a);
	Interval c; //Interval c(0, 0);
	c = a; //c.operator=(a);
	*/

	cout << "Journey begins..." << endl;
	{
		Journey b(550, a);
		cout << "Journey period = "
			 //<< b.Period()
			 << b->Period() //b.operator->()->Period()
			 << " seconds." << endl;
	}
	cout << "Journey ends." << endl;
}


















