#include <iostream>
#include <string>

using namespace std;

template<typename I, typename V>
class IndexedValue
{
public:
	IndexedValue(const I& i, const V& v) : index(i), value(v)
	{
	}

	I GetIndex() const
	{
		return index;
	}

	V GetValue() const
	{
		return value;
	}
	
	void SetValue(const V& v)
	{
		value = v;
	}

	void Print() const
	{
		cout << index << " => " << value << endl;
	}
private:
	I index;
	V value;
};

int main(void)
{
	IndexedValue<string, double> a("first", 12.34);
	//a.SetValue("Monday"); //Compile-time error
	a.SetValue(23.45);
	cout << "a:";
	a.Print();

	IndexedValue<string, double> b("second", 34.56);
	cout << "b:";
	b.Print();
	
	IndexedValue<int, string> c(1, "Monday");
	cout << "c:";
	c.Print();

	IndexedValue<int, double> d(2, 45.67);
	cout << "d:";
	d.Print();
}

















