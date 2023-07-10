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

	long GetHours()
	{
		return hours;
	}

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

	double GetNetIncome()
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

	// destructor
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

void CreateJill(void)
{
	Employee jill(170, 80); 
	cout << "Jill's income is "
		 << jill.GetNetIncome() 
		 << endl;
	//jill destroyed.
}

int main(void)
{
	Employee jack; // jack(0, 50);
	jack.SetHours(190); 
	cout << "Jack's income is "
		 << jack.GetNetIncome()
		 << endl;
	
	CreateJill();

	cout << "Number of employees: " 
		 << Employee::CountEmployees()
		 << endl;

	//jack destroyed.
}













