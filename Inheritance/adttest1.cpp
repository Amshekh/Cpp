#include "banking1.h"
#include <iostream>

using namespace Banking;
using namespace std;

int main(void)
{
	Account* jill = OpenAccount(4000);
	Account* jack = OpenAccount(10000, false);

	double amt;
	cout << "Enter amount to transfer: ";
	cin >> amt;

	try
	{
		jill->Transfer(amt, jack);
	}
	catch(InsufficientFunds)
	{
		cout << "Transfer failed due to lack of funds!" << endl;
	}

	cout << "Jill's Account ID is "
		 << jill->Id()
		 << " and Balance is "
		 << jill->Balance()
		 << endl;
	cout << "Jack's Account ID is "
		 << jack->Id()
		 << " and Balance is "
		 << jack->Balance()
		 << endl;

	CloseAccount(jack);
	CloseAccount(jill);
}
















