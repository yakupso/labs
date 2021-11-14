#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 310; i++)
		cout << i << ' ';

	cout << "\n";
	for (int i = 1; i <= 155; i++) {
		cout << (rand() % 310) << ' ';
		cout << (rand() % 310) << endl;
	}
	return 0;
}