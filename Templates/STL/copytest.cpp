#include "interval.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

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

	for_each(store.begin(), store.end(), Print);

	ofstream fout("store.dat");
	if(!fout)
		cout << "ERROR: Cannot write to store.dat" << endl;
	else
	{
		fout << store.size() << endl;
		copy(store.begin(), store.end(), 
			ostream_iterator<Interval>(fout, "\t"));
		fout.close();
	}
}

















