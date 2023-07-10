#include "genalgo.h"
#include <iostream>

using namespace std;

bool IsOdd(long value)
{
	return value & 1;
}

class IsBetween
{
public:
	IsBetween(long l, long h)
	{
		low = l;
		high = h;
	}

	bool operator()(long value) const
	{
		return (value > low) && (value < high);
	}
private:
	long low, high;
};

int main(void)
{
	long store[] = {415, 324, 237, 541, 158, 362, 675};
	cout << "All values: ";
	PrintAll(store, store + 7);

	cout << "Odd values: ";
	PrintIf(store, store + 7, IsOdd);

	cout << "Values between 200 and 400: ";
	PrintIf(store, store + 7, IsBetween(200, 400));
}
















