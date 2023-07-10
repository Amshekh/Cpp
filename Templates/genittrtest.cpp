#include "genittr.h"
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

	for(SimpleList<long>::Iterator i = store.Begin();
			i != store.End(); ++i)
	{
		cout << *i << endl;
	}

	cout << "---------------" << endl;

	while(!store.Empty())
	{
		cout << store.Front() << endl;
		store.PopFront();
	}
}














