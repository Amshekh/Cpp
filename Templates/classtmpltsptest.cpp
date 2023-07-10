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

static int counter;

template<typename V>
class IndexedValue<int, V> //Partial specialization
{
public:
	IndexedValue(const V& v) : value(v)
	{
		index = ++counter;
	}

	int GetIndex() const
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
		cout << "[" << index << "] => " << value << endl;
	}
private:
	int index;
	V value;
};

template<>
class IndexedValue<int, string> //Full specialization
{
public:
	IndexedValue(const string& v) : value(v)
	{
		index = ++counter;
	}

	int GetIndex() const
	{
		return index;
	}

	string GetValue() const
	{
		return value;
	}

	void SetValue(const string& v)
	{
		value = v;
	}

	void Print() const
	{
		cout << index << " => '" << value << "'" << endl;
	}
private:
	int index;
	string value;
};

int main(void)
{
	IndexedValue<string, double> a("first", 12.34);
	a.SetValue(23.45);
	cout << "a:";
	a.Print();

	IndexedValue<string, double> b("second", 34.56);
	cout << "b:";
	b.Print();
	
	IndexedValue<int, string> c("Monday");
	cout << "c:";
	c.Print();

	IndexedValue<int, double> d(45.67);
	cout << "d:";
	d.Print();
}

















