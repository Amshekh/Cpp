#include "banking2.h"
#include <iostream>

using namespace Banking;
using namespace std;

void DeductTax(Account* accounts[], int count)
{
	for(int i = 0; i < count; i++)
	{
		double e = accounts[i]->Balance() - 25000;
		if(e > 0)
			accounts[i]->Withdraw(0.05 * e);
	}
}

void PayAnnualInterest(Account* accounts[], int count)
{
	for(int i = 0; i < count; i++)
	{
		Profitable* p = dynamic_cast<Profitable*>(accounts[i]);
		if(p) p->AddInterest(1);
	}
}

int main(void)
{
	Account* bank[4];
	
	bank[0] = OpenAccount(9000, true);
	bank[1] = OpenAccount(20000, false);
	bank[2] = OpenAccount(30000, false);
	bank[3] = OpenAccount(39000, true);

	DeductTax(bank, 4);
	PayAnnualInterest(bank, 4);

	for(int i = 0; i < 4; i++)
		cout << bank[i]->Id() << '\t' << bank[i]->Balance() << endl;

	for(int i = 0; i < 4; i++)
		CloseAccount(bank[i]);
}

















