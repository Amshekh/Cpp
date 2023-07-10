#include "interval.h"
#include <iostream>
#include <list>
#include <queue>

using namespace std;

int main(void)
{
	//queue<Interval> store;
	queue<Interval, list<Interval> > store;

	store.push(Interval(3, 41));
	store.push(Interval(4, 32));
	store.push(Interval(5, 23));
	store.push(Interval(2, 54));
	store.push(Interval(1, 15));

	while(!store.empty())
	{
		cout << store.front() << endl;
		store.pop();
	}
}

















