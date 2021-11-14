#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const int CIRCLE_ARR_SZ = 3;
const int RECTANGLE_ARR_SZ = 4;
const double R = 5.0; // предельный размер геометрии фигуры

// Базовый абстрактный класс
class Figure {
public:
	double *geometry;
	double *indicators;

	// Чисто виртуальные
	virtual void move() = 0;
	virtual void rotate() = 0;
	virtual void print(ostream &out) const = 0;
	virtual double myrand(double mymin, double mymax) = 0;

	virtual ~Figure() {
		delete [] geometry;
		delete [] indicators;
	}

	friend ostream& operator<< (ostream& out , Figure const& figure);
};


// Класс кругов Circle (производный от
// класса Figure).
class Circle : public Figure {
public:
	static int CIRCLE_COUNT;
	/* Конструктор по умолчанию.*/
	Circle() {
		geometry = new double [CIRCLE_ARR_SZ];

		geometry[0] = myrand(0.0, 100.0*R) - 50*R; // x
		geometry[1] = myrand(0.0, 100.0*R) - 50*R; // y
		double D = 50 * R - max(abs(geometry[0]), abs(geometry[1]));
		geometry[2] = myrand(0.0, D) + 1; // r

		indicators = new double [3];

		indicators[0] = myrand(0.0, R); // speed
		indicators[1] = myrand(0.0, 3*R); // rotate speed
		indicators[2] = 0; // rotate angle

		CIRCLE_COUNT++;
	}

	// Конструктор круга с заданными параметрами.
	Circle(double x, double y, double r,
				double sp, double rs, double ra) {
		geometry = new double [CIRCLE_ARR_SZ];
		geometry[0] = x; // x
		geometry[1] = y; // y
		geometry[2] = r; // r

		indicators = new double [3];
		indicators[0] = sp; // speed
		indicators[1] = rs; // rotate speed
		indicators[2] = ra; // rotate angle
	}

	void move() {
		//geometry[0] += indicators[0] * cos(indicators[2]);
		//geometry[1] += indicators[0] * sin(indicators[2]); //
	}

	void rotate() {
		//indicators[2] += indicators[1];
	}

	void print(ostream &out) const override {
    	out  << "Circle:\n" << "\tx = " << geometry[0] << ", y = " << geometry[1]
        				<< endl << "\tRadius: " << geometry[2] << endl;
	}

	double myrand(double mymin, double mymax) {
		double x;
		x = mymin + ((double)rand() / RAND_MAX) * (mymax - mymin);

		return x;
	}

	~Circle() {
		delete [] geometry;
		delete [] indicators;
	}
};

// Класс прямоугольников Rectangle (производный от
// класса Figure).
class Rectangle : public Figure {
public:
	static int RECTANGLE_COUNT;

	Rectangle() {
		geometry = new double [RECTANGLE_ARR_SZ];
		geometry[0] = myrand(0.0, 100*R) - 50*R; // x
		geometry[1] = myrand(0.0, 100*R) - 50*R; // y
		double D = 50*R - abs(geometry[0]); 
		geometry[2] = myrand(0.0, (D - 1.0)) + 1; // w
		geometry[3] = myrand(0.0, (D - 1.0)) + 1; // h


		indicators = new double [3];
		indicators[0] = myrand(0.0, R); // speed
		indicators[1] = myrand(0.0, 3*R); // rotate speed
		indicators[2] = 0; // rotate angle

		RECTANGLE_COUNT++;
	}

	Rectangle(double x, double y, double w, double h,
				double sp, double rs, double ra) {
		geometry = new double [CIRCLE_ARR_SZ];
		geometry[0] = x; // x
		geometry[1] = y; // y
		geometry[2] = w; // w
		geometry[3] = h; // h

		indicators = new double [3];
		indicators[0] = sp; // speed
		indicators[1] = rs; // rotate speed
		indicators[2] = ra; // rotate angle
	}

	void move() {
		//geometry[0] += indicators[0] * cos(indicators[2]);
		//geometry[1] += indicators[0] * sin(indicators[2]);
	}

	void rotate() {
		//indicators[2] += indicators[1];
	}

	void print(ostream &out) const override {
    	out  << "Rectangle:\n" <<"\tx = " << geometry[0]  << ", y = " << geometry[1] <<
    			     endl << "\tWidht: " << geometry[2] << endl << "\tHight: " << geometry[3] << endl;
	}

	double myrand(double mymin, double mymax) {
		double x;
		x = mymin + ((double)rand() / RAND_MAX) * (mymax - mymin);

		return x;
	}
};

ostream& operator<< (ostream& out, const Figure &Figure) {
    Figure.print(out);
    return out;
}

double myrand(double mymin, double mymax) {
	double x;
	x = mymin + (double)(rand()) / (RAND_MAX / (mymax - mymin));

	return x;
}

int Circle::CIRCLE_COUNT = 0;
int Rectangle::RECTANGLE_COUNT = 0;

int main() {
	srand(time(NULL));
	int k = 18 + 10;
	double 	random_num;
	Figure *figures[k];

	for (int i = 0; i < k; i++) {
		random_num = myrand(0.0, 1.0);
		if (random_num <= 0.5)
			figures[i] = new Circle();
		else
			figures[i] = new Rectangle();
	}

	for (int i = 0; i < k; i++)
		cout << *figures[i] << endl;

	cout << "\nTotal rectangles: " << Rectangle::RECTANGLE_COUNT << endl;
	cout << "\nTotal circles: " << Circle::CIRCLE_COUNT << endl;

	return 0;
}