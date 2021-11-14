#include <iostream>

using namespace std;

class Matrix {
private:
	int n;
	double **matrix;

public:
	void spur();
	void swap();
	void min();
	void max();
	void print();

	Matrix(int n1=2)
	{
		n = n1;
		matrix = new double *[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new double [n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				matrix[i][j] = (i == j) ? 1:0;
	}

	Matrix(int n1, char c)
	{
		n = n1;
		matrix = new double *[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new double [n];

		cout << "\n\tEnter array:\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}
	}

	Matrix(int n1, bool flag)
	{
		n = n1;
		matrix = new double *[n];
		for (int i = 0; i < n; i++)
			matrix[i] = new double [n];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 1./(i + j + 1);
			}
		}
	}

	~Matrix()
	{
		for (int i = 0; i < n; ++i)
			delete matrix[i];
		delete *matrix;
	}
};


void Matrix::spur()
/* Функция поиска следа матрицы*/
{
	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += matrix[i][i];
	cout << "\nSpur = "<< sum << endl;
}

void Matrix::swap()
/* Вариант swap'a 1*/
{
	double *tmp;
	int i, j;
	cout << "\nEnter i, j: ";
	cin >> i >> j;

	tmp = matrix[i];
	matrix[i] = matrix[j];
	matrix[j] = tmp;
}

void Matrix::min()
/*Функция поиска минимума матрицы*/
{
	double mymin = matrix[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] < mymin)
				mymin = matrix[i][j];
		}
	}
	cout << "Min = " << mymin << endl;
}

void Matrix::max()
/*Функция поиска максимума функции*/
{
	double mymax = matrix[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] > mymax)
				mymax = matrix[i][j];
		}
	}
	cout << "Max = " << mymax << endl;
}

void Matrix::print()
/*Функция вывода матрицы*/
{
	cout << "\nArray:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int choice;
	char c;
	int n;

	cout << "\nChoice input method:  \n\t1) Enter;\n\t2) Generator;\n\t3) Identity;";
	cout << "\n\tEnter 1, 2 or 3: ";
	cin >> choice;

	if (choice == 1) {
		cout << "\n\tEnter n: ";
		cin >> n;
		Matrix mymatrix = Matrix(n, c);
		mymatrix.spur();
		mymatrix.min();
		mymatrix.max();
		mymatrix.print();
		mymatrix.swap();
		mymatrix.print();
	} 
	else if (choice == 2) {
		cout << "\n\tEnter n: ";
		cin >> n;
		Matrix mymatrix = Matrix(n, true);
		mymatrix.spur();
		mymatrix.min();
		mymatrix.max();				
		mymatrix.print();
		mymatrix.swap();
		mymatrix.print();
	} 
	else if (choice == 3) {
		cout << "\n\tEnter n: ";
		cin >> n;
		Matrix mymatrix = Matrix(n);
		mymatrix.spur();
		mymatrix.min();
		mymatrix.max();				
		mymatrix.print();
		mymatrix.swap();
		mymatrix.print();
	} 
	else {
		cout << "\nInvalid value";
		return 0;
	}
	return 0;
}