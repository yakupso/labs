#include <iostream>
#include <cstdlib>
using namespace  std;

void print_arr(short *arr, short n) 
{
	cout << "\nArray: [";
	for (short i = 0; i < n; i++){
		if (i+1 != n)
			cout << arr[i] << ", ";
		else
			cout << arr[i] << "]\n";
	}
}

void max_arr(short *arr, short n)
{
	short max_rise = 0;
	short max_len = 0;
	short start_point = -1;

	for (short i = 0; i < n-1; i++) {
		if (arr[i] < arr[i+1]) {
			if (start_point == -1)
				start_point = i;
		} 
		else {
			if (max_rise < (arr[i] - arr[start_point])) {
				max_rise = arr[i] - arr[start_point];
				max_len = i - start_point + 1;
			}
			start_point = -1;
		}
	}
	cout << "\nMax rise: " << max_rise << "\nLength of max rise: " << max_len << endl;
}

int main()
{
	short n = 30;
	short *arr = new short [n];

	for (short i = 0; i < n; i++) {
		arr[i] = rand() % 100;
	}
	print_arr(arr, n);
	max_arr(arr, n);

	return 0;
}