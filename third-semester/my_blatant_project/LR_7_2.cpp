#include <algorithm>
#include <ctime>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

#define CIRCLE_ARR_SZ 3
#define CIRCLEo_ARR_SZo 3
#define RECTANGLEo_ARR_SZo 4
// Предельный размер геометрии фигуры
#define R 2
#define H 100
#define PROB_CIRCLEo 0.5

const double PI = 3.14159265359;
    
const int K = 10 + 18;
const int AREA = H * R;

double myrando()
{
    double random_num;
    random_num = (double)(rand()) / RAND_MAX;

    return random_num;
}

// Базовый абстрактный класс
class Figureo {
protected:
    double* geometry;
    double* speeds = new double[3];
    double angle_movement;
    int geometry_sz;
    int dir_x, dir_y;
public:
    /* Конструктор по умолчанию.*/
    Figureo() {
        speeds[0] = myrando() * 2 + 1;
        speeds[1] = myrando() * 10 + 5;
        speeds[2] = myrando() * 360;
        speeds[2] = speeds[2] == 360 ? 0 : speeds[2];

        angle_movement = myrando() * 60 + 5;

        dir_x = dir_y = 1;
    }

    double get_angle_movement() {
      return angle_movement;
    }

    void set_dirs(int x, int y) {
        dir_x = x;
        dir_y = y;
    }

    pair<double, double> get_dirs() {
        return make_pair(dir_x, dir_y);
    }

    int get_size() {
        return geometry_sz;
    }

    pair<double, double> get_center() {
        return make_pair(geometry[0], geometry[1]);
    }

    virtual pair<double, double> get_params() = 0;
    
    double* get_speeds() {
        return speeds;
    }

    virtual vector<pair<double, double>> push_back_coords(double x, double y) {
        vector<pair<double, double>> res = {};
        return res;
    }

    friend pair<double, double> get_coord(double x, double y, Figureo& fig) {
        x -= fig.geometry[0];
        y -= fig.geometry[1];
        double fi = double(fig.speeds[2] * PI) / 180.;
        double x1 = x * cos(fi) - y * sin(fi);
        double y1 = x * sin(fi) + y * cos(fi);
        x = x1 + fig.geometry[0];
        y = y1 + fig.geometry[1];
        return make_pair(x, y);
    }

    double get_area() const {
        if (geometry_sz == 3) {
            return PI * geometry[2] * geometry[2];
        }
        else {
            return geometry[2] * geometry[3];
        }
    }

    // Чисто виртуальные
    virtual void move(double x, double y) = 0;
    virtual void rotate(double rot_angle) = 0;

    friend ostream& operator<<(ostream& stream, const Figureo& fig) {
        if (fig.geometry_sz == 4)
            stream << "Rectangleo:\n";
        else
            stream << "Circleo:\n";
        stream << "\t\tx = " << fig.geometry[0] << ", y = " << fig.geometry[1] 
                << "\n\t\tfirst_param = " << fig.geometry[2]; //!

        if (fig.geometry_sz == 4)
            stream << ", second_param = " << fig.geometry[3];
        stream << "\n\t\tspeed = " << fig.speeds[0] << ", angle_speed = " 
                << fig.speeds[1] << ", angle = " << fig.speeds[2];

        return stream;
    }

    friend bool operator<(const Figureo& f_elem, const Figureo& s_elem) {
        return f_elem.get_area() < s_elem.get_area();
    }

    friend bool operator==(const Figureo& f_elem, const Figureo& s_elem) {
        return f_elem.get_area() == s_elem.get_area();
    }

    friend bool operator>(const Figureo& f_elem, const Figureo& s_elem) {
        return f_elem.get_area() > s_elem.get_area();
    }

    virtual ~Figureo() {
        delete[] geometry;
        delete[] speeds;
    }
};

// Класс прямоугольников Rectangleo (производный от
// класса Figureo).
class Rectangleo : public Figureo {
public:
    static int RECTANGLEo_COUNT;

    /* Конструктор по умолчанию.*/
    Rectangleo() {
        geometry_sz = RECTANGLEo_ARR_SZo;
        geometry = new double [geometry_sz];

        geometry[0] = myrando() * AREA / 3 + AREA / 6;
        geometry[1] = myrando() * AREA / 3 + AREA / 6;
        geometry[2] = myrando() * (AREA / 4) + 1;
        geometry[3] = myrando() * (AREA / 4) + 1;

        RECTANGLEo_COUNT++;
    }

    pair<double, double> get_params() {
        return make_pair(geometry[2], geometry[3]);
    }

    void move(double x, double y) {
        geometry[0] = x;
        geometry[1] = y;
    }

    void rotate(double rot_angle) {
        speeds[2] = rot_angle;
    }

    vector<pair<double, double>> push_back_coords(double x, double y) {
        auto params = get_params();
        vector<pair<double, double>> result;
        result.push_back(get_coord(x + params.first / 2,
                                    y + params.second / 2, *this));
        result.push_back(get_coord(x - params.first / 2, 
                                    y + params.second / 2, *this));
        result.push_back(get_coord(x - params.first / 2, 
                                    y - params.second / 2, *this));
        result.push_back(get_coord(x + params.first / 2, 
                                    y - params.second / 2, *this));
        return result;
    }

    friend ostream& operator<<(ostream& stream, Rectangleo rec) {
        stream << "(" << rec.geometry[0] << ";" << rec.geometry[1] << ")," 
                << rec.geometry[2] << "," << rec.geometry[3]; //!
        return stream;
    }

    ~Rectangleo() {
        delete[] geometry;
        delete[] speeds;
    }
};

// Класс кругов Circleo (производный от
// класса Figureo).
class Circleo : public Figureo {
public:
    static int CIRCLEo_COUNT;

    /* Конструктор по умолчанию.*/
    Circleo() {
        geometry_sz = CIRCLEo_ARR_SZo;
        geometry = new double[geometry_sz];
        geometry[2] = myrando() * (AREA / 4) + 1;

        CIRCLEo_COUNT++;
    }

    pair<double, double> get_params() {
        return make_pair(geometry[2], 0);
    }

    void move(double x, double y) {
        geometry[0] = x;
        geometry[1] = y;
    }

    void rotate(double rot_angle){
        speeds[2] = rot_angle;
    }

    friend ostream& operator<< (ostream& stream, Circleo cir) {
        stream << "(" << cir.geometry[0] << "; " << cir.geometry[1] << "), " 
                << cir.geometry[2] << ", " << cir.geometry[3]; //!
        return stream;
    }

    ~Circleo() {
        delete[] geometry;
        delete[] speeds;
    }
};


bool is_move(double x, double y, Figureo& rec) {
    if (rec.get_size() == 4) {
            auto size = AREA;
            auto iffer([size](double x1, double y1)->bool {
                if (x1 <= 0 || x1 >= size || y1 <= 0 || y1 > size)
                    return false;
                return true;
            });
        auto coords = rec.push_back_coords(x, y);

        bool f1 = iffer(coords[0].first, coords[0].second);
        bool f2 = iffer(coords[1].first, coords[1].second);
        bool f3 = iffer(coords[2].first, coords[2].second);
        bool f4 = iffer(coords[3].first, coords[3].second);

        if (f1 && f2 && f3 && f4) {
            rec.move(x, y);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        double rad = rec.get_params().first;
        if (rad < x && rad < (AREA - x) && rad < y && rad < (AREA - y)) {
            rec.move(x, y);
            return true;
        }
        return false;
    }
}

bool is_rotate(double angle, Figureo& fig) {
    double old_angle = fig.get_speeds()[2];
    fig.rotate(old_angle + angle);
    auto [x, y] = fig.get_center();
            if (is_move(x, y, fig)) {
        return true;
    }
    else {
        fig.rotate(old_angle - angle);
        return false;
    }
}

pair<double, double> rand_coord() {
    double x = myrando() * AREA / 2;
    double y = myrando() * AREA / 2;
    double random_num;

    random_num = myrando();
    x = x + random_num < AREA ? x + random_num : AREA;

    random_num = myrando();
    y = y + random_num < AREA ? y + random_num : AREA;

    return make_pair(x, y);
}

bool smart_move(Figureo& rec, double x, double y) {
    for (int i = 0; i < 30; ++i) {
        if (!is_move(x, y, rec)) {
            auto coord = rand_coord();
            x = coord.first;
            y = coord.second;
        }
        else {
            return true;
        }
    }
    rec.move((AREA / 2), (AREA / 2));
    return true;
}

// Класс поля Field
class Field {
    Figureo** figureos;
    double dt;
public:
    /* Конструктор по умолчанию.*/
    Field() {
        int figureo_counter = 0;
        dt = 0.1;
        figureos = new Figureo * [K];

        for (int i = 0; i < K; ++i) {
            double chance = myrando();
            if (!(chance >= PROB_CIRCLEo)) {
                figureos[figureo_counter] = new Rectangleo();
                ++figureo_counter;
            }
            else {
                figureos[figureo_counter] = new Circleo();
                auto [x, y] = rand_coord();
                smart_move(*figureos[figureo_counter], x, y);
                ++figureo_counter;
            }
        }
    }

    Figureo** ticking() {
        for (int i = 0; i < K; ++i) {
            auto [x, y] = figureos[i]->get_center();
            double* speeds = figureos[i]->get_speeds();
            auto params = figureos[i]->get_params();
            double rad = figureos[i]->get_angle_movement() * PI / 180.;
            auto [dir_x, dir_y] = figureos[i]->get_dirs();

            x += cos(rad) * speeds[0] * dt * dir_x;
            y -= sin(rad) * speeds[0] * dt * dir_y;

            double paramtr = figureos[i]->get_size() > 3 ? 
                sqrt(params.first * params.first / 4 + params.second * 
                params.second / 4) : 
                (figureos[i]->get_params().first);

            if (!is_move(x, y, *figureos[i])) {
                if (figureos[i]->get_center().first + paramtr >= AREA - 1 ||
                        figureos[i]->get_center().first - paramtr <= 1) {
                    dir_x *= -1;
                }
                else {
                    dir_y *= -1;
                }
                figureos[i]->set_dirs(dir_x, dir_y);
            }

            if (!is_rotate(speeds[2] + speeds[1] * dt, *figureos[i])) {
                x += cos(rad) * speeds[0] * dt * dir_x;
                y -= sin(rad) * speeds[0] * dt * dir_y;
            }
        }
        return figureos;
    }

    double get_dt() {
        return dt;
    }

    Figureo** get_figureos() {
        return figureos;
    }
};


template <typename T>
void swapper(T& f_elem, T& s_elem) {
    swap(f_elem, s_elem);
}

template <typename T>
T* mysort(T* arr, long int size) {
    long int i = 0;
    long int j = size - 1;
    T tmp; 
    T mid = arr[size / 2];

    do {
        while (arr[i] < mid)
            i++;

        while (arr[j] > mid)
            j--;

        if (i <= j) {
            tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;

            i++; j--;
        }
    } while (i <= j);

    if (j > 0) 
        mysort(arr, j + 1);
    if (i < size) 
        mysort(&arr[i], size - i);

    return arr;
}

template <typename T>
bool find(T* arr, T elem, int size) {
    T* sorted = mysort(arr, size);
    return (binary_search(&sorted[0], &sorted[size - 1], elem));
}

int Circleo::CIRCLEo_COUNT = 0;
int Rectangleo::RECTANGLEo_COUNT = 0;

int main() {
    srand(time(NULL));
    Field field;

    ofstream new_fout("LR_7_2.txt"); new_fout.close();
    // Открываем поток.
    ofstream fout("LR_7_2.txt", ios_base::app);

    if (fout) {
        fout << "\nTotal rectangles: " << Rectangleo::RECTANGLEo_COUNT << endl;
        fout << "Total circles: " << Circleo::CIRCLEo_COUNT << endl;
        for (double time = 0.; time <= 5.; time += 0.1) {
            fout << "\nTime: " << time << endl;
            for (int i = 0; i < K; i++) {
                auto& elem = field.get_figures()[i];
                fout << "\n\t" << (i + 1) << ") " << *elem;
            }
            fout << "\n-----------------------------------------"
                    << "----------------------------------------\n\n";
            Figureo** figures = field.ticking();
        }
    }
    return 0;
}