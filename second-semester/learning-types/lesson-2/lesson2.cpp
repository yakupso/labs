#include <iostream>

int main()
{
	using namespace std;

	// 2.1 // при float -> int происходит отбрасывание дробной части
	float a1 = -1.1; float a2 = -1.5; float a3 = -1.9;
	float a4 =  1.1; float a5 =  1.5; float a6 =  1.9;
	int b1, b2, b3, b4, b5, b6;
	// явное преобразование типа
	b1 = int(a1); b2 = int(a2); b3 = int(a3);
	b4 = int(a4); b5 = int(a5); b6 = int(a6);

	cout << b1 << " " << b2 << " " << b3 << " " 
	     << b4 << " " << b5 << " " << b6 << "\n";
	// неявное преобразование типа
	b1 = a1;      b2 = a2;      b3 = a3;
	b4 = a4;      b5 = a5;      b6 = a6;

	cout << b1 << " " << b2 << " " << b3 << " " 
	     << b4 << " " << b5 << " " << b6 << "\n\n";


	// 2.2 // при double -> int происходит отбрасывание дробной части
	double d1 = -1.1; double d2 = -1.5; double d3 = -1.9;
	double d4 = 1.1;  double d5 = 1.5;  double d6 = 1.9;
	// явное преобразование типа
	b1 = int(d1); b2 = int(d2); b3 = int(d3);
	b4 = int(d4); b5 = int(d5); b6 = int(d6);

	cout << b1 << " " << b2 << " " << b3 << " " 
	     << b4 << " " << b5 << " " << b6 << "\n";
	// неявное преобразование типа
	b1 = d1;      b2 = d2;      b3 = d3;
	b4 = d4;      b5 = d5;      b6 = d6;

	cout << b1 << " " << b2 << " " << b3 << " " 
	     << b4 << " " << b5 << " " << b6 << "\n\n";


	// 2.3 // bool -> int работает; true == 1, false == 0
	int i = true;  // i == 1
	int j = false; // j == 0

	cout << i << " " << j << "\n\n";

	// 2.4 // int -> bool работает; !0 == true, 0 == false
	bool n = 5;
	bool m = 0;

	cout << n << " " << m << "\n\n";


	return 0;

}