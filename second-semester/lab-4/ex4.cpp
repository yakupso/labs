#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	bool flag;
	short counter = 0;
	short k = 0;
	short n;
	cout << "\nEnter n: ";
	cin >> n;

	short *arr = new short [n];
	for (short i = 2 ; counter != n; i++) {
		flag = true;
		for (short j = 2; j <= sqrt(i) && flag; j++) {	
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			arr[counter] = i;
			counter++;
		}
		
	}

	cout << "\nNums: [";
	for (short i = 0; i < n; i++) {
		if (i+1 != n)
			cout << arr[i] << ", ";
		else
			cout << arr[i] << "]\n";
	}

	return 0;
}