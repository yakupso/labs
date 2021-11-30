#ifndef LR_7_1
#define LR_7_1

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

const int CIRCLEz_ARR_SZ = 3;
const int RECTANGLEz_ARR_SZ = 4;
const double R = 5.0; // предельный размер геометрии фигуры

// Базовый абстрактный класс
class Figurez {
public:
	double *geometry;
	double *indicators;

	// Чисто виртуальные
	virtual void move() = 0;
	virtual void rotate() = 0;
	virtual void print(ostream &out) const = 0;
	virtual double myrandz(double mymin, double mymax) = 0;

	virtual ~Figurez() {
		delete [] geometry;
		delete [] indicators;
	}

	friend ostream& operator<< (ostream& out , Figurez const& figurez);
};


// Класс кругов Circlez (производный от
// класса Figurez).
class Circlez : public Figurez {
public:
	static int CIRCLEz_COUNT;
	/* Конструктор по умолчанию.*/
	Circlez() {
		geometry = new double [CIRCLEz_ARR_SZ];

		geometry[0] = myrandz(0.0, 100.0*R) - 50*R; // x
		geometry[1] = myrandz(0.0, 100.0*R) - 50*R; // y
		double D = 50 * R - max(abs(geometry[0]), abs(geometry[1]));
		geometry[2] = myrandz(0.0, D) + 1; // r

		indicators = new double [3];

		indicators[0] = myrandz(0.0, R); // speed
		indicators[1] = myrandz(0.0, 3*R); // rotate speed
		indicators[2] = 0; // rotate angle

		CIRCLEz_COUNT++;
	}

	// Конструктор круга с заданными параметрами.
	Circlez(double x, double y, double r,
				double sp, double rs, double ra) {
		geometry = new double [CIRCLEz_ARR_SZ];
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

	double myrandz(double mymin, double mymax) {
		double x;
		x = mymin + ((double)rand() / RAND_MAX) * (mymax - mymin);

		return x;
	}

	~Circlez() {
		delete [] geometry;
		delete [] indicators;
	}
};

// Класс прямоугольников Rectanglez (производный от
// класса Figurez).
class Rectanglez : public Figurez {
public:
	static int RECTANGLEz_COUNT;

	Rectanglez() {
		geometry = new double [RECTANGLEz_ARR_SZ];
		geometry[0] = myrandz(0.0, 100*R) - 50*R; // x
		geometry[1] = myrandz(0.0, 100*R) - 50*R; // y
		double D = 50*R - abs(geometry[0]); 
		geometry[2] = myrandz(0.0, (D - 1.0)) + 1; // w
		geometry[3] = myrandz(0.0, (D - 1.0)) + 1; // h


		indicators = new double [3];
		indicators[0] = myrandz(0.0, R); // speed
		indicators[1] = myrandz(0.0, 3*R); // rotate speed
		indicators[2] = 0; // rotate angle

		RECTANGLEz_COUNT++;
	}

	Rectanglez(double x, double y, double w, double h,
				double sp, double rs, double ra) {
		geometry = new double [CIRCLEz_ARR_SZ];
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

	double myrandz(double mymin, double mymax) {
		double x;
		x = mymin + ((double)rand() / RAND_MAX) * (mymax - mymin);

		return x;
	}
};

ostream& operator<< (ostream& out, const Figurez &Figurez) {
    Figurez.print(out);
    return out;
}

double myrandz(double mymin, double mymax) {
	double x;
	x = mymin + (double)(rand()) / (RAND_MAX / (mymax - mymin));
	return x;
}

int Circlez::CIRCLEz_COUNT = 0;
int Rectanglez::RECTANGLEz_COUNT = 0;

#endif // LR_7_1