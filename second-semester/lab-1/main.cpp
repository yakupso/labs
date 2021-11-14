// Вариант 3
#include <iostream>
#include "funcs.h"
using namespace std;

int main()
{
	char choice;
	int a, b, c, d;
	int num, nBegin;

	cout << "\nChoose one of the programs:";
	cout << "\n\ta) min;\n\tb) even;\n\tc) average;\n\td) fibonacci;\n\te) bit\n";
	cout << "Enter a, b, c, d or e here: ";
	cin >> choice;

	switch (choice)
	{
		case 'a':
			cout << "Enter numbers: ";
			cin >> a >> b >> c >> d;
			cout << "\nMinimum: " << min(a, b, c, d) << endl;
			break;
		case 'b':
			cout << "Enter numbers: ";
			cin >> a >> b >> c >> d;
			cout << "\nEven numbers: " << even(a, b, c, d) << endl;
			break;
		case 'c':
			cout << "Enter numbers: ";
			cin >> a >> b >> c >> d;
			cout << "\nAverage: " << average(a, b, c, d) << endl;
			break;
		case 'd':
			cout << "Enter amount and start number: ";
			cin >> num >> nBegin;
			fibonacci(num, nBegin);
			break;
		case 'e':
			cin >> a;
			bit(a);
			break;
		default:
			cout << "\nInvalid value." << endl;
	}
	return 0;
}