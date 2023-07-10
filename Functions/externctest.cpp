#include <iostream>

using namespace std;

extern "C" long BoxVolume(long, long, long, short);

int main(void)
{
	cout << "Enter box dimensions: ";
	
	long l, b, h;
	cin >> l >> b >> h;
	
	long v = BoxVolume(l, b, h, 1);

	cout << "Inner volume = " << v << endl;
}
















