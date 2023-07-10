#include <iostream>


class Employee
{
public:
	Employee(long h=0, float r=50)
	{
		hours = h;
		rate = r;
		count++;
		#ifdef _TESTING
		std::cout << "-- Employee constructor called." << std::endl;
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
		std::cout << "-- Employee destructor called." << std::endl;
		#endif
	}

private:
	long hours;
	float rate;
	static int count;
};

int Employee::count = 0;

class SalesPerson : public Employee
{
public:
	SalesPerson(long h, float r, double s) : Employee(h, r)
	{
		sales = s;
		#ifdef _TESTING
		std::cout << "-- SalesPerson constructor called." << std::endl;
		#endif
	}

	double GetSales() const
	{
		return sales;
	}

	void SetSales(double value)
	{
		sales = value;
	}

	double GetNetIncome() const
	{
		double income = Employee::GetNetIncome();
		
		if(sales >= 20000)
			income += 0.05 * sales;

		return income;
	}

	~SalesPerson()
	{
		#ifdef _TESTING
		std::cout << "-- SalesPerson destructor called." << std::endl;
		#endif
	}
private:
	double sales;
};













































