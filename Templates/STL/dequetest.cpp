#include "interval.h"
#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
	deque<Interval> store;
	
	store.push_back(Interval(3, 41));
	store.push_back(Interval(4, 32));
	store.push_back(Interval(5, 23));
	store.push_back(Interval(2, 54));
	store.push_back(Interval(1, 15));
	store.push_front(Interval(6, 30));

	for(deque<Interval>::iterator i = store.begin(); 
			i != store.end(); ++i)
	{
		cout << *i << endl;
	}

	deque<Interval>::iterator m = store.begin() + 2;
	cout << "Middle entry: " << *m << endl;
}

















