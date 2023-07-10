//#define _TESTING
#include "payroll2.h"
#include <iostream>

using namespace std;

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
		//if(i == 2 || i == 4)
		if(typeid(*group[i]) == typeid(SalesPerson))
		{
			SalesPerson* sp = static_cast<SalesPerson*>(group[i]);
			total += sp->GetSales();
		}
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
		new SalesPerson(185, 51, 35000)
	};

	cout << "Average income: " 
		 << GetAverageIncome(dept, 5)
		 << endl;

	cout << "Total sales: " 
		 << GetTotalSales(dept, 5)
		 << endl;

	for(int i = 0; i < 5; i++)	
		delete dept[i];
}


















