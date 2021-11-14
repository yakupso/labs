#include <iostream>
using namespace std;

int main()
{
	// Объявление переменных
	int i;
	double d;
	char c;
	// Объявление указателей
	int *pi;
	double *pd;
	char *pc;
	// Заполнение переменных с клавиатуры
	cout << "Enter values (int, double, char): ";
	cin >> i >> d >> c;
	// Присвоение указателям адресов переменных
	pi = &i;
	pd = &d;
	pc = &c;
	// Косвенное изменение значения переменных
	*pi += *pi;
	*pd *= 2;
	*pc += 5;
	// Косвенный вывод значения переменных, их адресов и адресов их указателей
	cout << "i = " << *pi << " (" << pi << ", " << &pi << ")" << endl;
	cout << "d = " << *pd << " (" << pd << ", " << &pd << ")" << endl;
	cout << "c = " << pc << " (" << ( const void * ) pc << ", " << &pc << ")" << endl; // ?

	return 0;
}