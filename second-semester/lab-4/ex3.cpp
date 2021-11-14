#include <iostream>
#include <cstring>
using namespace std;

const short n = 21;

void search(short *arr)
{
	short sup_arr[n+1];
	for (short i = 0; i <= n; i++)
		sup_arr[i] = 0;

	for (short i = 0; i < n; i++)
		sup_arr[arr[i]]++;

	for (short i = 0; i <= n; i++) {
		if (sup_arr[i]) {
			if (sup_arr[i] == 1)
				cout << i << " - " << sup_arr[i] << " time\n";
			else
				cout << i << " - " << sup_arr[i] << " times\n";
		}
	}
}

int main()
{
	short *arr = new short [n];
	for (short i = 0; i < n; i++)
		arr[i] = rand() % 21;

	cout << endl;
	search(arr);
	return 0;
}