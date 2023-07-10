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
	Employee* jack = new Employee;
	jack->SetHours(186);
	jack->SetRate(52);
	cout << "Jack's income is "
		 << jack->GetNetIncome()
		 << " and tax is "
		 << GetIncomeTax(*jack)
		 << endl;

	Employee* jill = new Employee(175, 95);
	cout << "Jill's income is "
		 << jill->GetNetIncome()
		 << " and tax is "
		 << GetIncomeTax(*jill)
		 << endl;

	delete jill;

	cout << "Number of employees: "
		 << Employee::CountEmployees()
		 << endl;

	delete jack;
}


















