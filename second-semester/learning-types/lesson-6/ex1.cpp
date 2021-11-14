// Вариант 21
#include <iostream>
#include <cmath>
using namespace std;

const int x1 = -10;
const int x2 = -6;
const int x3 = -4; 
const int x4 = 2;

int main() 
{
	double x, y;
	double R;

	cout << "Enter x: ";   cin >> x;
	cout << "\nEnter R: "; cin >> R;

	if (x == x1)
		y = 2;
	if ((x > x1) && (x < x2))
		y = -sqrt(R*R - (x + 8)*(x + 8)) + 2;
	if ((x >= x2) && (x <= x3))
		y = 2;
	if ((x > x3) && (x < x4))
		y = -x/2;
	if (x > x4)
		y = x - 3;

	cout << y;

	return 0;
}