#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

void solver (vector<int> &data, int solves[9], int count)
{
	int max_square = 0;              // a
	int max_cube = 0;                // б
	int min_nan = data[1];           // в
	int min_sum = data[1] + data[2]; // г
	int max_an = 1;                  // д
	int even = 0;                    // е
	int doubled_odd = 0;             // ж
	int full_square = 0;             // з
	int square_odd = 0;              // и

	
	for (int i = 0; i < data.size(); ++i) {
		// а, б
		if (max_square < (data[i] * data[i])) {
			max_square = data[i] * data[i];
			max_cube = data[i] * data[i] * data[i];
		}
		// в
		if (min_nan > ((i+1) * data[i])) {
			min_nan = (i+1) * data[i];
		}
		// г
		if (min_sum > (data[i-1] + data[i])) {
			min_sum = data[i-1] + data[i];
		}
		// е
		if (data[i] % 2 == 0) {
			even++;
		}
		// ж
		if ((data[i] % 2 == 0) && ((data[i]/2) % 2 != 0)) {
			doubled_odd++;
		}
		// з
		if (sqrt(data[i]) == int (sqrt(data[i]))) {
			full_square++;
		}
		// и
		if ((sqrt(data[i]) == int (sqrt(data[i]))) && (int (sqrt(data[i])) % 2)) {
			square_odd++;
		}
	}
	// д
	for (int i = 0; i < data.size(); ++i) {
		if (max_an <= (max_an * data[i]))
			max_an *= data[i];
		else
			break;
	}

	solves[0] = max_square;
	solves[1] = max_cube;
	solves[2] = min_nan;
	solves[3] = min_sum;
	solves[4] = max_an;
	solves[5] = even;
	solves[6] = doubled_odd;
	solves[7] = full_square;
	solves[8] = square_odd;
}

void console_input(vector<int> &data)
/* Ввод из консоли */
{
	int buffer = 1;
	cout << "\nWrite here: ";
	while (true) {  // Можно и без break'а обойтись
		cin >> buffer;
		if (buffer >= 0)
			data.push_back(buffer);
		else
			break;
    }
}

void file_input(vector <int> &data)
/* Ввод из файл */
{
	// Открываем поточек
	ifstream fin("input.txt");

	if (fin) {
		int num;
		while (fin >> num) {
			if (num >= 0)
				data.push_back(num);
			else
				break;
		}
		// Закрываем поточек
		fin.close();
	}
	else
		cout << "Error: file is not opened.";
}

void console_output(int solves[9])
/* Вывод в консоль */
{
	cout << "1) " << solves[0] << endl;
	cout << "2) " << solves[1] << endl;
	cout << "3) " << solves[2] << endl;
	cout << "4) " << solves[3] << endl;
	cout << "5) " << solves[4] << endl;
	cout << "6) " << solves[5] << endl;
	cout << "7) " << solves[6] << endl;
	cout << "8) " << solves[7] << endl;
	cout << "9) " << solves[8] << endl;
}

void file_output(int solves[9])
/* Вывод в файл */
{
	// Обнуляем файл или создаю, если его нет
	ofstream new_fout("output.txt"); new_fout.close();
	// Открываем поточек
	ofstream fout("output.txt", ios_base::app);

	if (fout) {
		for (int i = 0; i < 9; ++i)
			fout << i+1 << ") " << solves[i] << '\n';
		fout.close();
	}
}

/* main */
int main()
{
	int solves[9];  // Массив всех решений
	char choice[2]; // Массив с выбором пользователя
	int count;
	char is_continue = 'c';
	vector<int> data;


	cout << "\nHello there! Let's begin.\n";
	while (is_continue == 'c') {
		cout << "\nEnter 'a' for console input or 'b' for file input: ";
		cin >> choice[0];
		cout << "So, enter 'a' for console output or 'b' for file output: ";
		cin >> choice[1];

		if (choice[0] == 'a') {
			console_input(data);
			solver(data, solves, count);
			if (choice[1] == 'a') {
				cout << "\n";
				console_output(solves);
			}
			else {
				file_output(solves);
			}
		}
		else {
			file_input(data);
			solver(data, solves, count);
			if (choice[1] == 'a') {
				console_output(solves);
			}
			else {
				file_output(solves);
			}
			break;
		}
		cout << "\nEnter 'c' for contunue or 'q' for quit: ";
		repeat:
			cin >> is_continue;

		if ((is_continue != 'c') && (is_continue != 'q'))
			goto repeat;
		data.clear();
	}
	return 0;
}