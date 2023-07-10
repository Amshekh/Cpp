#include <iostream>

using namespace std;

class Employee
{
public:
	// zero-parameter constructor
	Employee()
	{
		hours = 0;
		rate = 50;
	}

	// parameterized constructor
	Employee(long h, float r)
	{
		hours = h;
		rate = r;
	}

	long GetHours()
	{
		return hours;
	}

	/*
 	void _ZN8Employee8SetHoursEl(Employee* this, long value)
	{
		this->hours = value;
	}
	*/
	void SetHours(long value)
	{
		hours = value;
	}

	float GetRate()
	{
		return rate;
	}
	
	void SetRate(float value)
	{
		rate = value;
	}

	/*
 	double _ZN8Employee12GetNetIncomeEv(Employee* this)
	{
		double income = this->hours * this->rate;
		long ot = this->hours - 180;

		if(ot > 0)
			income += 50 * ot;

		return income;
	}
	*/
	double GetNetIncome()
	{
		double income = hours * rate;
		long ot = hours - 180;

		if(ot > 0)
			income += 50 * ot;

		return income;
	}

private:
	long hours;
	float rate;
};

int main(void)
{
	Employee jack; // initialized using zero-parameter ctor	
	jack.SetHours(190); // _ZN8Employee8SetHoursEl(&jack, 190);
	cout << "Jack's income is "
		 << jack.GetNetIncome()
		 << endl;

	Employee jill(170, 80); // initialized using parameterized ctor
	cout << "Jill's income is "
		 << jill.GetNetIncome() // _ZN8Employee12GetNetIncomeEv(&jill);
		 << endl;
}













