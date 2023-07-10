//#define _TESTING
#include "payroll2.h"
#include <iostream>

using namespace std;

class SalesAgent : public SalesPerson
{
public:
	SalesAgent(double s) : SalesPerson(0, 0, s)
	{
	}

	double GetNetIncome() const
	{
		return 0.15 * GetSales();
	}
};

double GetAverageIncome(Employee* group[], int count)
{
	double total = 0;

	for(int i = 0; i < count; i++)
	{
		total += group[i]->GetNetIncome();
	}

	return total / count;
}

double GetTotalSales(Employee* group[], int count)
{
	double total = 0;

	for(int i = 0; i < count; i++)
	{
		SalesPerson* sp = dynamic_cast<SalesPerson*>(group[i]);
		if(sp) total += sp->GetSales();
	}

	return total;
}

int main(void)
{
	Employee* dept[] = {
		new Employee(186, 52),
		new Employee(190, 250),
		new SalesPerson(175, 55, 65000),
		new Employee(180, 90),
		new SalesPerson(185, 51, 35000),
		new SalesAgent(80000)
	};

	cout << "Average income: " 
		 << GetAverageIncome(dept, 6)
		 << endl;

	cout << "Total sales: " 
		 << GetTotalSales(dept, 6)
		 << endl;

	for(int i = 0; i < 6; i++)	
		delete dept[i];
}


















