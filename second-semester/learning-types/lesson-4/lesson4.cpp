#include <iostream>

int main()
{
	using namespace std;

	unsigned char uc;
	char c;
	uc = 15;
	c = uc;
	cout << c << endl;
	
	unsigned char uc1;
	char c1;
	c1 = -1;
	uc1 = c1;
	cout << c1 << endl;

	// a)
	cout << c << " " << uc << " " 
	     << c1 << " " << uc1 << endl;

	// б)
	unsigned long uli = -1;
	cout << uli; // 4294967295

	
	return 0;
}