#include <iostream>
#include <string>

using namespace std;

int Search(string key, string keys[], int count)
{
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

	int i = Search(name, names, 5);
	cout << "Your balance is " << balances[i] << endl;
}

int main(void)
{
	cout << "Welcome to our bank." << endl;
	Run();
	cout << "Goodbye from our bank." << endl;
}








