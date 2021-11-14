#include <iostream>

int main()
{
	using namespace std;
    
	// int
	short si;                // 2 байта
	int i;                   // 4 байта
	long li;                 // 4 байта
	long long lli;           // 8 байт
	unsigned short usi;      // 2 байта 
	unsigned int ui;         // 4 байта
	unsigned long uli;       // 4 байта
	unsigned long long ulli; // 8 байт

	// float
	float f;                 // 4 байта

	// double
	double d;                // 8 байт
	long double ld;          // 16 байт

	// bool
	bool b;                  // 1 байт

	// char и wсhar_t
	char c;                  // 1 байт
	wchar_t wc;              // 2 байта
	unsigned char uc;        // 1 байт

	int sz;

	sz = sizeof(si);
	cout << "Size of short int: " << sz << endl;
	sz = sizeof(i);
	cout << "Size of int: " << sz << endl;
	sz = sizeof(li);
	cout << "Size of long int: " << sz << endl;
	sz = sizeof(lli);
	cout << "Size of long long int: " << sz << endl;
	sz = sizeof(usi);
	cout << "Size of unsigned short int: " << sz << endl;
	sz = sizeof(ui);
	cout << "Size of unsigned int: " << sz << endl;
	sz = sizeof(uli);
	cout << "Size of unsigned long int: " << sz << endl;
	sz = sizeof(ulli);
	cout << "Size of unsigned long long int: " << sz << endl;

	sz = sizeof(f);
	cout << "\nSize of float: " << sz << endl;

	sz = sizeof(d);
	cout << "\nSize of double: " << sz << endl;
	sz = sizeof(ld);
	cout << "Size of long double: " << sz << endl;

	sz = sizeof(b);
	cout << "\nSize of bool: " << sz << endl;

	sz = sizeof(c);
	cout << "\nSize of char: " << sz << endl;
	sz = sizeof(wc);
	cout << "Size of wchar_t: " << sz << endl;
	sz = sizeof(uc);
	cout << "Size of unsigned char: " << sz << endl;


	return 0;
}