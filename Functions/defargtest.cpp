#include <iostream>
#include <cmath> //C++ version of math.h

using namespace std;

double Installment(double loan, short period, float rate=11)
{
	double amount = loan * pow(1 + rate / 100, period);

	return amount / (12 * period);
}

int main(void)
{
	cout << "Enter the amount and period of loan: ";
	
	double p;
	short n;
	cin >> p >> n;

	cout << "Installment for home-loan: "
		 << Installment(p, n, 9.5f)
		 << endl;
	cout << "Installment for personal-loan: "
		 << Installment(p, n) //Installment(p, n, 11)
		 << endl;
}















