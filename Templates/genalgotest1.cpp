#include "genittr.h"
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
	SimpleList<long> store;
	
	store.PushBack(415);
	store.PushBack(324);
	store.PushBack(237);
	store.PushBack(541);
	store.PushBack(158);
	store.PushBack(362);
	store.PushBack(675);

	cout << "All values: ";
	PrintAll(store.Begin(), store.End());

	cout << "Odd values: ";
	PrintIf(store.Begin(), store.End(), IsOdd);

	cout << "Values between 200 and 400: ";
	PrintIf(store.Begin(), store.End(), IsBetween(200, 400));
}
















