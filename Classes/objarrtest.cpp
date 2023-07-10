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
		#ifdef _TESTING
		cout << "-- Employee instance created." << endl;
		#endif
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
		#ifdef _TESTING
		cout << "-- Employee instance destroyed." << endl;
		#endif
	}

private:
	long hours;
	float rate;
	static int count;
};

int Employee::count = 0;

double GetIncomeTax(const Employee& emp)
{
	double i = emp.GetNetIncome();

	return i <= 10000 ? 0 : 0.15 * (i - 10000);
}

int main(void)
{
	Employee dept[5];
	
	for(int i = 0; i < 5; i++)
	{
		dept[i].SetRate(55);
		dept[i].SetHours(170 + 5 * i);

		cout << (i + 1) << '\t'
			 << dept[i].GetNetIncome() << '\t'
			 << GetIncomeTax(dept[i]) << endl;
	}
}


















