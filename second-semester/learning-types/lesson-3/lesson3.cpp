#include <iostream>

int main()
{
	using namespace std;

	// a) unsigned char
	unsigned char uc;
	uc = 250;
	cout << uc << endl;
	uc += 10; // 
	cout << uc << endl << endl;

	// b) char
	char c;
	c = 100;
	cout << c << endl;
	c += 30; // B
	cout << c << endl << endl;

	// unsigned short int
	unsigned short us;
	us = 65530;
	cout << us << endl;
	us += 10; // 4
	cout << us << endl << endl;

	// short int
	short s;
	s = 32760;
	cout << s << endl;
	s += 10; // -32766
	cout << s << endl << endl;

	return 0;
}