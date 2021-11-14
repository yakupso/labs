#include <iostream>
using namespace std;

int min(int a, int b, int c, int d)
{
	int minimum = a;

	if (b < minimum)
		minimum = b;
	if (c < minimum)
		minimum = c;
	if (d < minimum)
		minimum = d;
	return minimum;
}

int even(int a, int b, int c, int d)
{
	int count = 0;

	if (a % 2 == 0)
		count++;
	if (b % 2 == 0)
		count++;
	if (c % 2 == 0)
		count++;
	if (d % 2 == 0)
		count++;
	return count;
}

double average(int a, int b, int c, int d)
{
	double medium = (a + b + c + d) / 4.0;
	return medium;
}

void fibonacci(int num, int nBegin)
{	
	int first = 1, second = 1;
	int temp;

	cout << "\nOutput: ";

	for (int i = 3; i <= nBegin; i++){
		temp = first;
		first = second;
		second += temp;
	}

	for (int i = nBegin + 1; i <= nBegin + num; i++){
		temp = first;
		first = second;
		second += temp;
		cout << first << ' ';
	}
	cout << "\n";
}

void bit(int a)
{
	for (int i = 31; i >= 0; i--){
		cout << ((a >> i) & 1);
	}
}