#include <iostream>

using namespace std;

double Average(double first, double second, double& dev)
{
	dev = first > second ? (first - second) / 2 : (second - first) / 2;
	
	return (first + second) / 2;
}

int main(void)
{
	cout << "Enter two real values: ";

	double x, y;
	cin >> x >> y;

	double d;
	double a = Average(x, y, d);

	cout << "Average is " << a
		 << " with deviation of " << d
		 << endl;
}












