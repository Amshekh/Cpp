#include <iostream>
#include <cmath>

using namespace std;

//_Z11Installmentdsf
double Installment(double loan, short period, float rate)
{
	double amount = loan * pow(1 + rate / 100, period);

	return amount / (12 * period);
}

//_Z11Installmentds
inline double Installment(double loan, short period)
{
	return Installment(loan, period, period < 5 ? 11 : 11.5);
}

int main(void)
{
	cout << "Enter the amount and period of loan: ";
	
	double p;
	short n;
	cin >> p >> n;

	cout << "Installment for home-loan: "
		 << Installment(p, n, 9.5f) //_Z11Installmentdsf
		 << endl;
	cout << "Installment for personal-loan: "
		 << Installment(p, n) //_Z11Installmentds
		 << endl;
}















