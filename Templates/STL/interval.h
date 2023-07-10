#ifndef INTERVAL_H
#define INTERVAL_H

#include <iostream>

class Interval
{
public:
	Interval(long m=0, long s=0)
	{
		minutes = m + s / 60;
		seconds = s % 60;
	}

	long Time() const
	{
		return 60 * minutes + seconds;
	}

	Interval operator+(const Interval& other) const
	{
		long m = minutes + other.minutes;
		long s = seconds + other.seconds;

		return Interval(m, s);
	}

	bool operator<(const Interval& other) const
	{
		return Time() < other.Time();
	}

	bool operator>(const Interval& other) const
	{
		return Time() > other.Time();
	}

	bool operator==(const Interval& other) const
	{
		return Time() == other.Time();
	}

private:
	long minutes;
	long seconds;

friend std::ostream& operator<<(std::ostream&, const Interval&);
friend std::istream& operator>>(std::istream&, Interval&);
};

std::ostream& operator<<(std::ostream& out, const Interval& value)
{
	out << value.minutes << ':' << value.seconds;

	return out;
}

std::istream& operator>>(std::istream& in, Interval& value)
{
	char ch;

	in >> value.minutes >> ch >> value.seconds;

	return in;
}

#endif










