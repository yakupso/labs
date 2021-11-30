#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

double myrand_8_1(double mymin, double mymax) {
	double x;
	x = mymin + (double)(rand()) / (RAND_MAX / (mymax - mymin));

	return x;
}

class Circle_8_1 {
	double radius;
public:
	Circle_8_1() {
		radius = myrand_8_1(2., 3.3);
	}

	double get_area() const {
		return PI * radius * radius;
	}
	friend ostream& operator<<(ostream& stream, const Circle_8_1& circle_8_1) {
        stream << circle_8_1.get_area(); return stream;
    }
	friend bool operator<(const Circle_8_1& f_elem, const Circle_8_1& s_elem) {
        return f_elem.get_area() < s_elem.get_area();
    }
    friend bool operator<=(const Circle_8_1& f_elem, const Circle_8_1& s_elem) {
        return f_elem.get_area() <= s_elem.get_area();
    }
    friend bool operator==(const Circle_8_1& f_elem, const Circle_8_1& s_elem) {
        return f_elem.get_area() == s_elem.get_area();
    }
    friend bool operator>(const Circle_8_1& f_elem, const Circle_8_1& s_elem) {
        return f_elem.get_area() > s_elem.get_area();
    }
    friend bool operator>=(const Circle_8_1& f_elem, const Circle_8_1& s_elem) {
        return f_elem.get_area() >= s_elem.get_area();
    }
    friend double operator+(const Circle_8_1& f_elem, const Circle_8_1& s_elem) {
        return f_elem.get_area() + s_elem.get_area();
    }
    operator double() const { 
    	return get_area(); 
    }
};


class Square_8_1 {
	double side;
public:
	Square_8_1() {
		side = myrand_8_1(4., 7.);
	}

	double get_area() const {
		return side * side;
	}

	friend ostream& operator<<(ostream& stream, const Square_8_1& square_8_1) {
        stream << square_8_1.get_area(); return stream;
    }
	friend bool operator<(const Square_8_1& f_elem, const Square_8_1& s_elem) {
        return f_elem.get_area() < s_elem.get_area();
    }
    friend bool operator<=(const Square_8_1& f_elem, const Square_8_1& s_elem) {
        return f_elem.get_area() <= s_elem.get_area();
    }
    friend bool operator==(const Square_8_1& f_elem, const Square_8_1& s_elem) {
        return f_elem.get_area() == s_elem.get_area();
    }
    friend bool operator>(const Square_8_1& f_elem, const Square_8_1& s_elem) {
        return f_elem.get_area() > s_elem.get_area();
    }
    friend bool operator>=(const Square_8_1& f_elem, const Square_8_1& s_elem) {
        return f_elem.get_area() >= s_elem.get_area();
    }
    friend double operator+(const Square_8_1& f_elem, const Square_8_1& s_elem) {
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
	double result = 0;
	for (int i = 0; i < arr_size; i++)
		result += double(arr[i]);
	return (result / arr_size);
}
/* ---------------------------------------------------------------- */