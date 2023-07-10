#include "interval.h"
#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int main(void)
{
	//priority_queue<Interval> store;
	//priority_queue<Interval, vector<Interval> > store;
	priority_queue<Interval, vector<Interval>, greater<Interval> > store;

	store.push(Interval(3, 41));
	store.push(Interval(4, 32));
	store.push(Interval(5, 23));
	store.push(Interval(2, 54));
	store.push(Interval(1, 15));

	while(!store.empty())
	{
		cout << store.top() << endl;
		store.pop();
	}
}

















