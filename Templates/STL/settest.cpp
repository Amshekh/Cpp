#include "interval.h"
#include <iostream>
#include <set>
#include <functional>

using namespace std;

int main(void)
{
	//set<Interval> store;
	set<Interval, greater<Interval> > store;
	
	store.insert(Interval(3, 41));
	store.insert(Interval(4, 32));
	store.insert(Interval(5, 23));
	store.insert(Interval(2, 54));
	store.insert(Interval(1, 15));
	store.insert(Interval(2, 101));

	for(set<Interval>::iterator i = store.begin(); 
			i != store.end(); ++i)
	{
		cout << *i << endl;
	}

}

















