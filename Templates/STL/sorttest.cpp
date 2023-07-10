#include "interval.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void Print(const Interval& i)
{
	cout << i << endl;
}

int main(void)
{
	vector<Interval> store;
	
	store.push_back(Interval(3, 41));
	store.push_back(Interval(4, 32));
	store.push_back(Interval(5, 23));
	store.push_back(Interval(2, 54));
	store.push_back(Interval(1, 15));

	//sort(store.begin(), store.end());
	sort(store.begin(), store.end(), greater<Interval>());

	for_each(store.begin(), store.end(), Print);
}

















