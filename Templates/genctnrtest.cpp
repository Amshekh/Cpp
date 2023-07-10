#include "genctnr.h"
#include <iostream>

using namespace std;

int main(void)
{
	SimpleList<long> store;
	
	store.PushBack(415);
	store.PushBack(324);
	store.PushBack(237);
	store.PushBack(541);
	store.PushBack(158);

	while(!store.Empty())
	{
		cout << store.Front() << endl;
		store.PopFront();
	}

	cout << "---------------" << endl;

	while(!store.Empty())
	{
		cout << store.Front() << endl;
		store.PopFront();
	}
}














