#include <iostream>
#include <cmath>
using namespace std;

int odd(int a, int b, int c, int d)
{
	int counter = 0;

	if (a % 2 != 0)
		counter++;
	if (b % 2 != 0)
		counter++;
	if (c % 2 != 0)
		counter++;
	if (d % 2 != 0)
		counter++;

	return counter;
}

int square(int a, int b, int c, int d)
{
	int area = abs((c-a) * (b-d));
	return area;
}

int length(int a, int b, int c, int d)
{
	int diagonal = sqrt((c-a)*(c-a) + (b-d)*(b-d));
	return diagonal;
}

void fibonacci(int num, int nBegin)
{
	int a=1, b=1;
	int tmp;                             // 1, 1, 2, | 3, 5, 8, 13, 21
										 // a  b
	for(int i=3; i <= nBegin; i++){		 // t  a  b+=t
		tmp = a;
		a = b;
		b += tmp;
	}
	for(int i = nBegin + 1; i <= nBegin + num; i++){
		tmp = a;
		a = b;
		b += tmp;
		cout << a << ' ';
	}
}
