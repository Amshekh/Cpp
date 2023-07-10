#include <iostream>

using namespace std;

class Employee
{
public:
	Employee(long h=0, float r=50)
	{
		hours = h;
		rate = r;
		count++;
	}

	long GetHours() const
	{
		return hours;
	}

	void SetHours(long value)
	{
		hours = value;
	}

	float GetRate() const
	{
		return rate;
	}
	
	void SetRate(float value)
	{
		rate = value;
	}

	/*
	double _ZKN8Employee12GetNetIncomeEv(const Employee* this)
	{
		double income = this->hours * this->rate;
		long ot = this->hours - 180;

		if(ot > 0)
			income += 50 * ot;

		return income;
	}
 	*/
	double GetNetIncome() const
	{
		double income = hours * rate;
		long ot = hours - 180;

		if(ot > 0)
			income += 50 * ot;

		return income;
	}

	static int CountEmployees()
	{
		return count;
	}

	~Employee()
	{
		count--;
	}

private:
	long hours;
	float rate;
	static int count;
};

int Employee::count = 0;

double GetIncomeTax(const Employee& emp)
{
	double i = emp.GetNetIncome(); //_ZKN8Employee12GetNetIncomeEv(&emp)

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
	
	Employee jill(175, 120);
	cout << "Jill's income is "
		 << jill.GetNetIncome() 
		 << " and tax is "
		 << GetIncomeTax(jill)
		 << endl;

	cout << "Number of employees: " 
		 << Employee::CountEmployees()
		 << endl;

}













