#include "banking2.h"
#include <ctime>

namespace Banking
{
	class CurrentAccount : public Account
	{
	public:
		void Deposit(double);
		void Withdraw(double) throw (InsufficientFunds);
	};

	class SavingsAccount : public Account, public Profitable
	{
	public:
		SavingsAccount();
		void Deposit(double);
		void Withdraw(double) throw (InsufficientFunds);
		double AddInterest(short);
	};

	Account::Account()
	{
		id = 0;
		balance = 0;
	}

	long Account::Id() const
	{
		return id;		
	}

	double Account::Balance() const
	{
		return balance;
	}

	void Account::Transfer(double amount, Account* other)
	throw (InsufficientFunds)
	{
		if(other != this)
		{
			this->Withdraw(amount);
			other->Deposit(amount);
		}
	}
	
	void CurrentAccount::Deposit(double amount)
	{
		if(balance < 0)
			amount *= 0.9;
		balance += amount;
	}
	
	void CurrentAccount::Withdraw(double amount)
	throw (InsufficientFunds)
	{
		balance -= amount;
	}

	SavingsAccount::SavingsAccount()
	{
		balance = 1000;
	}

	void SavingsAccount::Deposit(double amount)
	{
		balance += amount;
	}

	void SavingsAccount::Withdraw(double amount)
	throw (InsufficientFunds)
	{
		if(balance - amount < 1000)
			throw InsufficientFunds();
		balance -= amount;
	}

	double SavingsAccount::AddInterest(short period)
	{
		double interest = 0.06 * balance * period;
		balance += interest;
		return interest;
	}

	Account* OpenAccount(double amount, bool savings)
	{
		static long nextid = time(0) % 1000000;
		Account* acc;

		if(savings)
			acc = new SavingsAccount;
		else
			acc = new CurrentAccount;

		acc->id = nextid++;
		acc->Deposit(amount);

		return acc;
	}

	void CloseAccount(Account* acc)
	{
		delete acc;
	}
}


















