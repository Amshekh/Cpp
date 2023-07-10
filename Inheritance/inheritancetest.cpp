#define _TESTING
#include "payroll1.h"
#include <iostream>

using namespace std;

double GetIncomeTax(const Employee& emp)
{
	double i = emp.GetNetIncome();

	return i <= 10000 ? 0 : 0.15 * (i - 10000);
}

double GetIncomeTax(const SalesPerson& emp)
{
	double i = emp.GetNetIncome();

	return i <= 10000 ? 0 : 0.15 * (i - 10000);
}

int main(void)
{
	Employee jack(186, 52);
	cout << "Jack's income is "
		 << jack.GetNetIncome()
		 << " and tax is "
		 << GetIncomeTax(jack)
		 << endl;
	
	SalesPerson jill(186, 52, 60000);
	cout << "Jill's income is "
		 << jill.GetNetIncome() 
		 << " and tax is "
		 << GetIncomeTax(jill)
		 << endl;

	cout << "Number of employees: " 
		 << Employee::CountEmployees()
		 << endl;

}













