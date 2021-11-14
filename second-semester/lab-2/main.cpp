#include <iostream>
#include "funcs.h"
using namespace std;

int main()
{
	char choice;
	int a, b, c, d;
	int num, nBegin;

	cin >> choice;

	switch(choice)
	{
		case 'a':
			cin >> a >> b >> c >> d;
			cout << odd(a, b, c, d);
			break;
		case 'b':
			cin >> a >> b >> c >> d;
			cout << square(a, b, c, d);
			break;
		case 'c':
			cin >> a >> b >> c >> d;
			cout << length(a, b, c, d);
			break;
		case 'd':
			cin >> num >> nBegin;
			fibonacci(num, nBegin);
			break;
		default:
			cout << "Invalid value";
			break;
	}

	return 0;
}