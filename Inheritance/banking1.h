#ifndef BANKING1_H
#define BANKING1_H

namespace Banking
{
	class InsufficientFunds{};

	class Account
	{
	public:
		Account();
		long Id() const;
		double Balance() const;
		virtual void Deposit(double) = 0;
		virtual void Withdraw(double) throw (InsufficientFunds) = 0;
		void Transfer(double, Account*) throw (InsufficientFunds);
		virtual ~Account(){}
	protected:
		double balance;
	private:
		long id;

	friend Account* OpenAccount(double, bool);
	};

	Account* OpenAccount(double, bool=true);

	void CloseAccount(Account*);
	
	class CurrentAccount : public Account
	{
	public:
		void Deposit(double);
		void Withdraw(double) throw (InsufficientFunds);
	};

	class SavingsAccount : public Account
	{
	public:
		SavingsAccount();
		void Deposit(double);
		void Withdraw(double) throw (InsufficientFunds);
		double AddInterest(short=1);
	};
}

#endif



















