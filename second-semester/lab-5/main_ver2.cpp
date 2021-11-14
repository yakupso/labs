#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

using namespace std;

int console_input(vector<int> &data, int &n)
/* Ввод из консоли */
{
	double buffer;
	cout << "\nEnter n: ";
	cin >> n;
	cout << "\nEnter sequence here: ";
	for (int i = 1; i <= n; i++) {
		cin >> buffer;
		data.push_back(buffer);
    }
    return n;
}

int file_input(vector<int> &data, int &n)
/* Ввод из файла */
{
	ifstream fin("input.txt");

	if (fin) {
		double buffer;
		fin >> n;
		for (int i = 1; i <= n; i++) {
			fin >> buffer;
			data.push_back(buffer);
		}
		fin.close();
		return n;
	}
	else {
		cout << "Error: file is not opened.";
		return 0;
	}
}

void console_solver(vector<int> &data, int &n)
{
	double num;
	// a)
	cout << "\nAnswers:\n\ta) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		for (int j = 0; j < i; j++) {
			num += data[j];
		}
		cout << num << ' ';
	}
	// b)
	cout << "\n\tb) ";
	for (int i = 0; i < n; i++) {
		num = data[0];
		cout << num * data[i] << ' ';
	}
	// c)
	cout << "\n\tc) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		for (int j = 0; j < i; j++) {
			num += fabs(data[j]);
		}
		cout << num << ' ';
	}
	// d)
	cout << "\n\td) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		for (int j = 0; j < i; j++) {
			num *= -data[j];
		}
		cout << num << ' ';
	}
	// e)
	cout << "\n\te) ";
	for (int i = 0; i < n; i++) {
		if ((i+1) % 2)
			cout << -data[i] << ' ';
		else 
			cout << data[i] << ' ';
	}
	// f)
	cout << "\n\tf) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		int fac = 1;
		for (int j = 1; j <= i + 1; j++) {
			fac *= j;
		}
		cout << num + fac << ' ';
	}
}

void file_solver(vector<int> &data, int &n) 
{
	double num;
	ofstream new_fout("output.txt"); 
	new_fout.close();

	ofstream fout("output.txt", ios_base::app);
	// a)
	fout << "Answers:\n\ta) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		for (int j = 0; j < i; j++) {
			num += data[j];
		}
		fout << num << ' ';
	}
	// b)
	fout << "\n\tb) ";
	for (int i = 0; i < n; i++) {
		num = data[0];
		fout << num * data[i] << ' ';
	}
	// c)
	fout << "\n\tc) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		for (int j = 0; j < i; j++) {
			num += fabs(data[j]);
		}
		fout << num << ' ';
	}
	// d)
	fout << "\n\td) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		for (int j = 0; j < i; j++) {
			num *= -data[j];
		}
		fout << num << ' ';
	}
	// e)
	fout << "\n\te) ";
	for (int i = 0; i < n; i++) {
		if ((i+1) % 2)
			fout << -data[i] << ' ';
		else 
			fout << data[i] << ' ';
	}
	// f)
	fout << "\n\tf) ";
	for (int i = 0; i < n; i++) {
		num = data[i];
		int fac = 1;
		for (int j = 1; j <= i + 1; j++) {
			fac *= j;
		}
		fout << num + fac << ' ';
	}
}

int main()
{
	int n;
	char is_continue = 'Y';
	char choice[2];
	vector<int> data;

	cout << "\nWelcome!\n" << endl;
	while ((is_continue == 'Y') || (is_continue == 'y')) {
		cout << "Select input method: \n\ta) Console input; \n\tb) File input;";
		cout << "\nInput method: ";
		cin >> choice[0];
		cout << "Select output method: \n\ta) Console output; \n\tb) File output;";
		cout << "\nOutput method: ";
		cin >> choice[1];

		if (choice[0] == 'a') {
			console_input(data, n);

			if (choice[1] == 'a')
				console_solver(data, n);
			else
				file_solver(data, n);
			cout << "\nDo you want to continue? [Y/n]: ";
			cin >> is_continue;
		}
		else {
			file_input(data, n);

			if (choice[1] == 'a')
				console_solver(data, n);
			else
				file_solver(data, n);
			is_continue = 'N';
		}
	}
	return 0;
}