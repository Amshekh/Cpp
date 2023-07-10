#include <iostream>
#include <string>

using namespace std;

int Search(string key, string keys[], int count)
{
	if(key[0] != 'j')
		throw 'j';

	if(key.size() < 4)
		throw 4;

	for(int i = 0; i < count; i++)
		if(keys[i] == key) return i;

	throw key;
}

void Run(void)
{
	string names[] = {"jack", "jill", "john", "jeff", "jane"};
	long balances[] = {9500, 15000, 12750, 18500, 6225};

	cout << "Enter your name: ";
	string name;
	cin >> name;

	try
	{
		int i = Search(name, names, 5);
		cout << "Your balance is " << balances[i] << endl;
	}
	catch(string e)
	{
		cout << "No such name: " << e << endl;
	}
	catch(char)
	{
		cout << "Invalid name!" << endl;
	}
}

int main(void)
{
	cout << "Welcome to our bank." << endl;
	try
	{
		Run();
	}
	catch(...)
	{
		cout << "Run error!" << endl;
	}
	cout << "Goodbye from our bank." << endl;
}












