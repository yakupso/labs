#include "cmath"
#include <QPainter>
#include <fstream>
#include <sstream>

#include <string>

#ifndef STAR_H
#define STAR_H
const int dim = 2;
int numStars = 300;
const int borderMassC = 10;
const double G = 6.67408e-11, dt = 10000;
double systemRadius = 1e12, distConnect = 1e10;
const long double massSun   = 1.98892e30,
             massJup   = 1898.6e24,
             massUran  = 86.832e24,
             massEarth = 5.9742e24,
             massVenus = 4.867e24;
const long double borderMass[] = {borderMassC*massEarth, borderMassC*massUran, borderMassC*massJup, borderMassC*massSun};
const QColor colStar[] = {Qt::cyan, Qt::darkGreen, Qt::magenta, Qt::yellow, Qt::white};
const int sizeStar[] = {6, 7, 8, 9};
const int nColor = sizeof(colStar) / sizeof(colStar[0]);


class star {
public:
    static int starCounter;
    double x[dim];
    double v[dim];
    long double m;
    int size;
    double f[dim];
    QColor col;
    void setCol(long double m);
    void setSize(long double m);
    star(double *coord, double *speed, long double mass);
    ~star() {starCounter--;}
};
int star::starCounter = 0;

void star::setCol(long double m) {
    // col = colStar[nColor-1];  // не годится, если будут объединения объектов, функция намного лучше
    for (int i = 0; i < nColor-1; ++i) {
        if (m <= borderMass[i]) {
            col = colStar[i];
            break;
        }
        else {
            col = colStar[4];
        }
    }
}

void star::setSize(long double m) {
    for (int i = 0; i < nColor-1; ++i) {
        if (m <= borderMass[i]) {
            size = sizeStar[i];
            break;
        }
    }
}

star::star(double *coord, double *speed, long double mass) {
    for(int k = 0; k < dim; ++k) {
        x[k] = coord[k];
        v[k] = speed[k];
    }
    m = mass;
    setCol(m);
    setSize(m);
    starCounter++;
}

class galaxy {
public:
    int num;
    star** stars;
//    galaxy(int n = numStars):num(n) {
//        stars = new star* [num];
//        double x1[dim] = {0}, v1[dim] = {0};
//        stars[0] = new star(x1, v1, massSun); // самый массивный объект в начале координат
//        double rad;
//        for (int i = 1; i < num-1; ++i) {
//            rad = 0;
//            double R = rand() * systemRadius / RAND_MAX,
//            fi  = (2 * M_PI * rand()) / RAND_MAX,
//            theta = (M_PI * rand()) / RAND_MAX;
//            x1[0] = R  * cos(fi);
//            x1[1] = R  * sin(fi);
//            if (dim == 3) {
//                x1[0] *= sin(theta);
//                x1[1] *= sin(theta);
//                x1[3] = R * cos(theta);
//            }
//            for (int k = 0; k < dim; ++k) {
//                rad += x1[k] * x1[k];
//            }
//// вторая космическая скорость
//            double absV = sqrt(G * stars[0]->m / sqrt(rad)), alpha = (2 * M_PI * rand()) / RAND_MAX;
//// если размерность 3, нужен еще один угол как для координат(два угла годятся и для плоскости)
////            v1[0] = absV * cos(alpha);
////            v1[1] = absV * sin(alpha);
//            v1[0] =  absV * sin(fi);
//            v1[1] = -absV * cos(fi); // скорость направлена вдоль окружности с центром в начале координат
//            stars[i] = new star(x1, v1, massEarth / num * (6 * i));
//        }
//        //stars[0] = new star(x1, v1, 1.98892e34);
//        //stars[1] = new star(x1, v1, massJup);
//        //stars[2] = new star(x1, v1, massJup);
//    };

    galaxy(int n, double systemRadius_, double distConnect_) {
        num = n;
        systemRadius = systemRadius_;
        distConnect = distConnect_;
        stars = new star* [num];
        double x1[dim] = {0}, v1[dim] = {0};
        stars[0] = new star(x1, v1, massSun); // самый массивный объект в начале координат
        double rad;
        for (int i = 1; i < num; ++i) {
            rad = 0;
            double  R = rand() * systemRadius / RAND_MAX,
                    fi  = (2 * M_PI * rand()) / RAND_MAX,
                    theta = (M_PI * rand()) / RAND_MAX;
            x1[0] = R  * cos(fi);
            x1[1] = R  * sin(fi);
            if (dim == 3) {
                x1[0] *= sin(theta);
                x1[1] *= sin(theta);
                x1[3] = R * cos(theta);
            }
            for (int k = 0; k < dim; ++k) {
                rad += x1[k] * x1[k];
            }
// вторая космическая скорость
            double absV = sqrt(G * stars[0]->m / sqrt(rad)), alpha = (2 * M_PI * rand()) / RAND_MAX;
// если размерность 3, нужен еще один угол как для координат(два угла годятся и для плоскости)
//            v1[0] = absV * cos(alpha);
//            v1[1] = absV * sin(alpha);
            v1[0] =  absV * sin(fi);
            v1[1] = -absV * cos(fi); // скорость направлена вдоль окружности с центром в начале координат
            stars[i] = new star(x1, v1, massEarth / num * (6 * i));
        }
        //stars[0] = new star(x1, v1, 1.98892e34);
        //stars[1] = new star(x1, v1, massJup);
        //stars[2] = new star(x1, v1, massJup);
    };
    ~galaxy(){delete[] stars; star::starCounter = 0;};
    double border[dim];

//    std::string file = "/Users/yakupso/Desktop/yakupso/qt_proj/starsCreation/input.txt";
//    std::fstream fin(file, fin.in);//std::ios::);
//    fin >> double k;
//    fin.close();

    //std::fstream fout("/Users/yakupso/Desktop/yakupso/qt_proj/starsCreation/output.txt", std::ios::out);
    //fout << ;
    //fout.close();

    void changeSize(long double m, int& size) {
        for (int i = 0; i < nColor-1; ++i) {
            if (m <= borderMass[i]) {
                size = sizeStar[i];
                break;
            }
        }
    }

    void changeColor(long double m, QColor& col) {
        for (int i = 0; i < nColor-1; ++i) {
            if (m <= borderMass[i]) {
                col = colStar[i];
                break;
            }
        }
    }

    void move() {
        double dist;
        double dCoord[dim];
        for (int i = 0; i < num; ++i) { // force nullification
            for (int k = 0; k < dim; ++k) {
                if (stars[i]) {
                    stars[i]->f[k] = 0;
                }
            }
        }
        for (int i = 0; i < num; i++) {
            if (stars[i]) {
                for (int j = i + 1; j < num; j++) {
                    if (i != j && stars[j]) {
                        dist = 0;
                        for (int k = 0; k < dim; ++k) {
                            dCoord[k] = stars[i]->x[k] - stars[j]->x[k];
                            dist += dCoord[k] * dCoord[k];
                        }
                        if (sqrt(dist) < distConnect) {
                            long double tmpM = stars[i]->m + stars[j]->m, tmpX[dim], tmpV[dim];
                            for (int k = 0; k < dim; ++k) {
                                tmpX[k] = (stars[i]->x[k] * stars[i]->m + stars[j]->x[k] * stars[j]->m)/tmpM;
                                tmpV[k] = (stars[i]->v[k] * stars[i]->m + stars[j]->v[k] * stars[j]->m)/tmpM;
                            }
                            delete stars[j];
                            stars[j] = nullptr;
                            stars[i]->m = tmpM;
                            changeSize(stars[i]->m, stars[i]->size);
                            changeColor(stars[i]->m, stars[i]->col);
                            for (int k = 0; k < dim; ++k) {
                                stars[i]->x[k] = tmpX[k];
                                stars[i]->v[k] = tmpV[k];
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0; i < num; i++){
            if(stars[i]){
                for(int j = i + 1; j < num; j++){
                    if(i != j && stars[j]){
                        dist = 0;
                        for(int k = 0; k < dim; ++k){
                            dCoord[k] = stars[i]->x[k] - stars[j]->x[k];
                            dist += dCoord[k] * dCoord[k];
                        }
                        // dist = sqrt(dist); // для знаменателя пока квадрат, потом возьмем корень
                        for(int k = 0; k < dim; ++k){
                            long double tmp = G * stars[i]->m * stars[j]->m / dist;
                            stars[i]->f[k] -= tmp * dCoord[k] / sqrt(dist);
                            stars[j]->f[k] += tmp * dCoord[k] / sqrt(dist);
                        }
                    }
                }
            }
        }
        for(int i = 0; i < num; ++i){
            if(stars[i]) {
                for(int k = 0; k < dim; ++k) {
                    stars[i]->v[k] += dt * stars[i]->f[k] / stars[i]->m; //можно не делить на массу, а выше суммировать ускорение
                }
                for(int k = 0; k < dim; ++k) {
                    stars[i]->x[k] += dt * stars[i]->v[k];
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, galaxy& obj) {
        stream << "Number of objects: ";
        stream << star::starCounter << std::endl;
        for (int i = 0; i < numStars; i++) {
            stream << "\nStar #" << i << ":";
            if (obj.stars[i] != nullptr) {
                stream << "\n\tMass: " << obj.stars[i]->m << std::endl;
                stream << "\n\tVelocities: Vx = " << obj.stars[i]->v[0] << " Vy = " << obj.stars[i]->v[1] << std::endl;
                stream << "\n\tCoordinates: X = " << obj.stars[i]->x[0] << " Y = " << obj.stars[i]->x[1] << std::endl;
            }
            else {
                stream << " DESTROYED" << std::endl;
            }
        }
        return stream;
    }

//    friend std::istream& operator>>(std::istream& stream, double obj[3]) {
//        // количество объектов
//        for (int i = 0; i < 3; i++) {
//            stream >> obj[i];
//        }

//        return stream;
//    }
};

std::istream& operator>>(std::istream& stream, double obj[3]) {
        // количество объектов
        for (int i = 0; i < 3; i++) {
            stream >> obj[i];
        }

        return stream;
    }

#endif // STAR_H
