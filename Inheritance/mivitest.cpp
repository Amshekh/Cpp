#include <iostream>

using namespace std;

class TaxPayer
{
public:
	TaxPayer(long pn)
	{
		pin = pn;
		count++;
	}

	long PIN() const
	{
		return pin;
	}

	virtual double AnnualIncome() const = 0;

	double Tax() const
	{
		double e = AnnualIncome() - 180000;
		return e > 0 ? 0.15 * e : 0;
	}

	virtual ~TaxPayer()
	{
		count--;
	}

	static int Count()
	{
		return count;
	}
	
private:
	long pin;
	static int count;
};

int TaxPayer::count = 0;

void Print(const TaxPayer* t)
{
	cout << "PIN = " << t->PIN()
		 << " and Tax = " << t->Tax() << endl;
}

class Employee : public virtual TaxPayer
{
public:
	Employee(long pn, double sy) : TaxPayer(pn)
	{
		salary = sy;
	}

	double AnnualIncome() const
	{
		return 14 * salary;
	}

private:
	double salary;
};

class Dealer : public virtual TaxPayer
{
public:
	Dealer(long pn, double ss) : TaxPayer(pn)
	{
		sales = ss;
	}

	double AnnualIncome() const
	{
		return 0.10 * sales;
	}

private:
	double sales;
};

class SalesPerson : public Employee, public Dealer
{
public:
	SalesPerson(long pn, double sy, double ss) : Employee(pn, sy),
												 Dealer(pn, ss),
												 TaxPayer(pn)
	{
	}

	double AnnualIncome() const
	{
		return Employee::AnnualIncome()
			+ 0.5 * Dealer::AnnualIncome();
	}
};


int main(void)
{
	Employee* jill = new Employee(123456, 25000);
	Dealer* jack = new Dealer(234567, 4000000);
	SalesPerson* jeff = new SalesPerson(345678, 16000, 2000000);

	cout << "Jill the Employee: ";
	Print(jill);
	cout << "Jack the Dealer: ";
	Print(jack);
	cout << "Jeff the SalesPerson: ";
	//Print(static_cast<Employee*>(jeff));
	Print(jeff);


	cout << "Number of TaxPayers: " 
		 << TaxPayer::Count() << endl;

	delete jeff;
	delete jack;
	delete jill;
}























