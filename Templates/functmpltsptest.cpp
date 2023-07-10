#include <iostream>

using namespace std;

template<typename T>
T Minimum(T first, T second)
{
	cout << "Minimizing values" << endl;

	if(first < second)
		return first;
	
	return second;
}

template<>
long Minimum(long first, long second) //explicit specialization.
{
	cout << "Minimizing long values." << endl;
	
	long third = first - second;
	
	return second + (third & (third << 31));
}

int main(void)
{
	double a = 12.34, b = 23.45;
	cout << "Original values: a = " << a << ", b = " << b << endl;
	double md = Minimum(a, b); //Minimum<double>(a, b)
	cout << "Their minimum = " << md << endl;

	long c = 43, d = 34;
	cout << "Original values: c = " << c << ", d = " << d << endl;
	long ml = Minimum(c, d); //Minimum<long>(c, d)
	cout << "Their minimum = " << ml << endl;
}



















