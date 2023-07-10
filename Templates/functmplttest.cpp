#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/*
void Swap(long& first, long& second)
{
	long third = first;

	first = second;
	second = third;
}

void Swap(double& first, double& second)
{
	double third = first;

	first = second;
	second = third;
}
*/

template<typename T>
void Swap(T& first, T& second)
{
	T third = first;

	first = second;
	second = third;
}

template<typename T>
T Convert(const string& source)
{
	stringstream ss;
	T result;

	ss << source;
	ss >> result;
	
	return result;
}

int main(void)
{
	long a = 123, b = 234;
	cout << "Original values: a = " << a << ", b = " << b << endl;
	Swap(a, b); //Swap<long>(a, b) type-inference
	cout << "Swapped values: a = " << a << ", b = " << b << endl;
	
	double c = 34.56, d = 45.67;
	cout << "Original values: c = " << c << ", d = " << d << endl;
	Swap(c, d);
	cout << "Swapped values: c = " << c << ", d = " << d << endl;
	Swap(d, c);
	//Swap(a, d); //Compile-time error.
	
	string e = "3.2";
	double f = Convert<double>(e); //explicit specification.
	cout << "Square of " << e << " = " << f * f << endl;
}


















