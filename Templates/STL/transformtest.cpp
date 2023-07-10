#include "interval.h"
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

long IntervalToTime(const Interval& i)
{
	return i.Time();
}

int main(void)
{
	ifstream fin("store.dat");

	if(!fin)
		cout << "ERROR: Cannot read from store.dat" << endl;
	else
	{
		int n;
		fin >> n;

		vector<long> store(n);
		transform(istream_iterator<Interval>(fin), 
			istream_iterator<Interval>(), 
			store.begin(), IntervalToTime);

		fin.close();

		long total = 0;
		for(vector<long>::iterator i = store.begin();
				i != store.end(); ++i)
			total += *i;

		cout << "Total time = " << total << " seconds." << endl;
	}
}



















