#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>

using namespace std;

const double PI = 3.14159265359;

double myrand(double mymin, double mymax) {
	double x;
	x = mymin + (double)(rand()) / (RAND_MAX / (mymax - mymin));

	return x;
}

class Circle {
	double radius;
public:
	Circle() {
		radius = myrand(1., 3.3);
	}

	double get_area() const {
		return PI * radius * radius;
	}

	friend ostream& operator<<(ostream& stream, const Circle& circle) {
        stream << circle.get_area(); return stream;
    }
	friend bool operator<(const Circle& f_elem, const Circle& s_elem) {
        return f_elem.get_area() < s_elem.get_area();
    }
    friend bool operator<=(const Circle& f_elem, const Circle& s_elem) {
        return f_elem.get_area() <= s_elem.get_area();
    }
    friend bool operator==(const Circle& f_elem, const Circle& s_elem) {
        return f_elem.get_area() == s_elem.get_area();
    }
    friend bool operator>(const Circle& f_elem, const Circle& s_elem) {
        return f_elem.get_area() > s_elem.get_area();
    }
    friend bool operator>=(const Circle& f_elem, const Circle& s_elem) {
        return f_elem.get_area() >= s_elem.get_area();
    }
    friend double operator+(const Circle& f_elem, const Circle& s_elem) {
        return f_elem.get_area() + s_elem.get_area();
    }
    operator double() const { 
    	return get_area(); 
    }
};


class Square {
	double side;
public:
	Square() {
		side = myrand(8., 10.);
	}

	double get_area() const {
		return side * side;
	}

	friend ostream& operator<<(ostream& stream, const Square& square) {
        stream << square.get_area(); return stream;
    }
	friend bool operator<(const Square& f_elem, const Square& s_elem) {
        return f_elem.get_area() < s_elem.get_area();
    }
    friend bool operator<=(const Square& f_elem, const Square& s_elem) {
        return f_elem.get_area() <= s_elem.get_area();
    }
    friend bool operator==(const Square& f_elem, const Square& s_elem) {
        return f_elem.get_area() == s_elem.get_area();
    }
    friend bool operator>(const Square& f_elem, const Square& s_elem) {
        return f_elem.get_area() > s_elem.get_area();
    }
    friend bool operator>=(const Square& f_elem, const Square& s_elem) {
        return f_elem.get_area() >= s_elem.get_area();
    }
    friend double operator+(const Square& f_elem, const Square& s_elem) {
        return f_elem.get_area() + s_elem.get_area();
    }
    operator double() const { 
    	return get_area(); 
    }
};

/* Пирамидальная сортировка (1 вариант) */
/* ---------------------------------------------------------------- */
template <class T> void sift_down(T *arr, int root, int bottom)
/* Функция "просеивания" через пирамиду - формирование пирамиды */
{
	int max_child; // индекс максимального потомка
	bool done = false; // флаг того, что пирамида сформирована

	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done)) {
		if (root * 2 == bottom)    // если мы в последнем ряду,
			max_child = root * 2;    // запоминаем левый потомок
		// иначе запоминаем больший потомок из двух
		else if (arr[root * 2] > arr[root * 2 + 1])
			max_child = root * 2;
		else
			max_child = root * 2 + 1;

		// если элемент вершины меньше максимального потомка
		if (arr[root] < arr[max_child]) {
			T tmp = arr[root]; // меняем их местами
			arr[root] = arr[max_child];
			arr[max_child] = tmp;
			root = max_child;
		} else
			done = true; // пирамида сформирована
	}
}

template <class T> void pyramid_sort(T *arr, int arr_size = 10)
/* Функция сортировки на пирамиде */
{
	// Формируем нижний ряд пирамиды
	for (int i = (arr_size / 2); i >= 0; i--)
		sift_down(arr, i, arr_size - 1);
	// Просеиваем через пирамиду остальные элементы
	for (int i = arr_size - 1; i >= 1; i--) {
		T tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		sift_down(arr, 0, i - 1);
	}
}
/* ---------------------------------------------------------------- */


/* Среднее арифметическое значения массива (6 вариант) */
/* ---------------------------------------------------------------- */
template <class T> double average(T *arr, int arr_size = 10)
/* Функция вычисления среднего арифметического значения массива */
{
	double result = double(arr[0]);
	for (int i = 1; i < arr_size; i++)
		result += double(arr[i]);
	return (result / arr_size);
}
/* ---------------------------------------------------------------- */

int main() {
	srand(time(NULL));
	int k = 10;

	// Инициализация четырех массивов:
	int *integers = new int [k];
	for (int i = 0; i < k; i++)
		integers[i] = rand() % k;
	double *doubles = new double [k];
	for (int i = 0; i < k; i++)
		doubles[i] = (double)(rand()) / (RAND_MAX / k);
	Square *squares = new Square [k];
	Circle *circles = new Circle [k];

	// Вывод содержимого всех массивов:
	cout << "\nIntegers: ";
	for (int i = 0; i < k; i++)
		cout << integers[i] << ' ';
	cout << "\nDoubles: ";
	for (int i = 0; i < k; i++)
		cout << doubles[i] << ' ';
	cout << "\nSquares: ";
	for (int i = 0; i < k; i++)
		cout << squares[i] << ' ';
	cout << "\nCircles: ";
	for (int i = 0; i < k; i++)
		cout << circles[i] << ' ';

	// Сортировка каждого массива и их вывод:
	pyramid_sort(integers);
	pyramid_sort(doubles);
	pyramid_sort(squares);
	pyramid_sort(circles);
	cout << "\n\nIntegers (sorted): ";
	for (int i = 0; i < k; i++)
		cout << integers[i] << ' ';
	cout << "\nDoubles (sorted): ";
	for (int i = 0; i < k; i++)
		cout << doubles[i] << ' ';
	cout << "\nSquares (sorted): ";
	for (int i = 0; i < k; i++)
		cout << squares[i] << ' ';
	cout << "\nCircles (sorted): ";
	for (int i = 0; i < k; i++)
		cout << circles[i] << ' ';

	// Вывод среднего каждого массива:
	cout << "\n\nAverage of integers: " << average(integers);
	cout << "\nAverage of doubles: " << average(doubles);
	cout << "\nAverage of squares: " << average(squares);
	cout << "\nAverage of circles: " << average(circles) << endl;
	
	return 0;
}