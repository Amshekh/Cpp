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

	for(int i = 0; i < 5; i++)	
		delete dept[i];
}


















