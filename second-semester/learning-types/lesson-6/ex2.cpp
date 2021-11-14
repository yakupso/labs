// Вариант 21
#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	double x, y;
	double R;

	cout << "Enter coordinates: "; 
	cin >> x >> y;

	cout << "Enter R: ";
	cin >> R;

	if ((y <= x + R) && ((x <= 0) || (y >= 0)) 
		&& (x*x + y*y <= R*R))
		cout << "Hit\n";
	else 
		cout << "Miss\n";

	return 0;
}

