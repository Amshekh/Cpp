#include "interval.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

typedef map<string, Interval> Storage;

int main(void)
{
	Storage store;

	store.insert(make_pair("monday", Interval(3, 41)));
	store.insert(make_pair("tuesday", Interval(4, 32)));
	store.insert(make_pair("wednesday", Interval(5, 23)));
	store.insert(make_pair("thursday", Interval(2, 54)));
	store.insert(make_pair("friday", Interval(1, 15)));

	for(Storage::iterator i = store.begin();
			i != store.end(); ++i)
	{
		cout << i->first << " => " << i->second << endl;
	}

	string key;
	cout << "Key: ";
	cin >> key;

	Storage::iterator k = store.find(key);
	if(k != store.end())
		cout << "Value = " << k->second << endl;
	else
		cout << "No such key!" << endl;
}

















