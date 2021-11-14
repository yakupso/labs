#include <iostream>

int main()
{
	using namespace std;

	unsigned long int ui;
	long int i;
	
	// a)
	float f;
	int q = 1;
	i = -1;
	ui = i;
	f = ui;
	cout << f << endl;
	f += 1;
	cout << f << endl; // надо добавить 7936

	// б)
	double d;
	d = ui;
	cout << d << endl;
	d += 1;
	cout << d << endl; // 7704

	/*while (q != 0){ 
		cin >> q;
		cout << f + q << endl;
	}*/

	// в)
	float delta;
	f = 1.0;
	delta = 0.1; // delta == 1e-8

	// г)
	f = 10.0;
	delta = 0.1; // delta = 1e-7


	return 0;
}