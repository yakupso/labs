#include <iostream>
#include <fstream>

using namespace std;

// Функция увеличения матрицы (добавление пустых элементов в концы массивов).
void enlarge_matrix(int*& values, int*& indeces, int& size) {
    int* vHelper = values;
    int* iHelper = indeces;
    values = new int[++size];
    indeces = new int[size];
    for (int i = 0; i < size - 1; ++i) {
        values[i] = vHelper[i];
        indeces[i] = iHelper[i];
    }
    delete[] vHelper;
    delete[] iHelper;
}

// Функция смещения всех элементов массивов вправо, начиная с [column].
void move_element(int* values, int* indeces, int size, int column) {
    for (int i = size - 1; i > column; --i) {
        values[i] = values[i - 1];
        indeces[i] = indeces[i - 1];
    }
}

// Функция удаления нулей.
void remove_zeros(int* values, int* indeces, int& size) {
    int *vHelper = new int[0], *iHelper = new int[0], hSize = 0;
    for (int i = 0; i < size; ++i) {
        if (values[i] != 0) {
            enlarge_matrix(vHelper, iHelper, hSize);
            vHelper[hSize - 1] = values[i];
            iHelper[hSize - 1] = indeces[i];
        }
    }
    values = vHelper;
    indeces = iHelper;
    size = hSize;
    delete[] vHelper;
    delete[] iHelper;
}

// Класс матриц в CRS формате.
class Matrix {
    // Инициализация массивов значений, индексов и индексации строк
    int *values, *indeces, *counters;
    // и их размеров.
    int viSize, cSize;
public:
    Matrix() {
        viSize = cSize = 0;
        values = new int[viSize];
        indeces = new int[viSize];
        counters = new int[cSize];
    }
    // Конструктор единичной матрицы.
    Matrix(int n) {
        cSize = n + 1;
        viSize = n;
        values = new int[viSize];
        indeces = new int[viSize];
        counters = new int[cSize];
        counters[0] = 0;
        for (int i = 0; i < viSize; ++i) {
            values[i] = 1;
            indeces[i] = i;
            counters[i + 1] = counters[i] + 1;
        }
    }
    // Конструктор нулевой матрицы.
    Matrix(int n, int m) {
        cSize = n + 1;
        viSize = 0;
        values = new int[viSize];
        indeces = new int[viSize];
        counters = new int[cSize];
        counters[0] = 0;
        for (int i = 0; i < viSize; ++i) {
            counters[i + 1] = 0;
        }
    }

    // Вклеивание элемента.
    void insert_element(int i, int j, int value)
    {
        int row = counters[i + 1] - counters[i];
        for (int k = 0; k < row; ++k) {
            // При существовании ненулового [i][j]-го элемента в матрице
            // вставляем новое значение на его место.
            if (j == indeces[k + counters[i]]) {
                values[j] = value;
                // Выход.
                return;
            }
        }
        // При отсутствии такого элемента, увеличиваем матрицу на единицу
        // и сдвигаем все правые элементы вправо, освобождая место
        // для нового значения.
        enlarge_matrix(values, indeces, viSize);
        int newColumn = counters[i];
        for (int k = 0; k < row; ++k) {
            if (j > indeces[newColumn + k]) {
                ++newColumn;
            }
        }
        move_element(values, indeces, viSize, newColumn);
        for (int k = i + 1; k < cSize; ++k) {
            ++counters[k];
        }
        values[newColumn] = value;
        indeces[newColumn] = j;
    }

    // Функция транспонирования.
    void transposition()
    {
        Matrix result;
        result.cSize = cSize;
        result.counters = new int[cSize];
        result.counters[0] = 0;
        for (int i = 0; i < cSize - 1; ++i) {
            int* vHelper = new int[0], * iHelper = new int[0], hSize = 0;
            for (int j = 0; j < viSize; ++j) {
                if (i == indeces[j]) {
                    enlarge_matrix(vHelper, iHelper, hSize);
                    vHelper[hSize - 1] = values[j];
                    int newColumn = 0;
                    while (j > counters[newColumn] - 1) {
                        ++newColumn;
                    }
                    iHelper[hSize - 1] = newColumn - 1;
                }
            }
            result.counters[i + 1] = result.counters[i] + hSize;
            for (int j = 0; j < hSize; ++j) {
                enlarge_matrix(result.values, result.indeces, result.viSize);
                result.values[result.viSize-1] = vHelper[j];
                result.indeces[result.viSize-1] = iHelper[j];
            }
            delete[] vHelper;
            delete[] iHelper;
        }
        *this = result;
    }

    friend Matrix operator+(Matrix lhs, Matrix rhs);
    friend Matrix operator*(Matrix lhs, Matrix rhs);
    friend ostream& operator<<(ostream& out, Matrix mat);
    friend istream& operator>> (istream& in, Matrix& mat);

    // Функция создания матрицы достижимости.
    Matrix create_reach_matrix()
    {
        Matrix matrix = *this;
        Matrix helper(matrix.cSize - 1);
        Matrix result(matrix.cSize - 1);
        helper = matrix;
        for (int i = 1; i < matrix.cSize - 1; ++i) {
            result = result + helper;
            helper = helper * matrix;
        }
        for (int i = 0; i < result.viSize; ++i) {
            result.values[i] = 1;
        }
        delete[] helper.values; delete[] helper.indeces; delete[] helper.counters;
        delete[] matrix.values; delete[] matrix.indeces; delete[] matrix.counters;
        return result;
    }
};

// Оператор ввода матрицы.
istream& operator>>(istream& in, Matrix& mat) {
    in >> mat.cSize;
    ++mat.cSize;
    mat.counters = new int[mat.cSize];
    for (int i = 0; i < mat.cSize; ++i) {
        mat.counters[i] = 0;
    }
    int size;
    in >> size;
    for (int k = 0; k < size; ++k) {
        int i, j;
        in >> i >> j;
        mat.insert_element(i, j, 1);
    }
    return in;
}

// Оператор вывода матрицы.
ostream& operator<<(ostream& stream, Matrix mat) {
    stream << "Values:\n";
    for (int i = 0; i < mat.viSize; ++i) {
        stream <<to_string(mat.values[i]);
        if (i != mat.viSize - 1) {
            stream << " ";
        }
    }
    stream << "\nIndeces:\n";
    for (int i = 0; i < mat.viSize; ++i) {
        stream <<to_string(mat.indeces[i]);
        if (i != mat.viSize - 1) {
            stream << " ";
        }
    }
    stream << "\nCounters:\n";
    for (int i = 0; i < mat.cSize; ++i) {
        stream << to_string(mat.counters[i]);
        if (i != mat.cSize - 1) {
            stream << " ";
        }
    }
    stream << "\n";
    return stream;
}

// Оператор сложения матриц.
Matrix operator+(const Matrix lhs, const Matrix rhs) {
    Matrix result;
    result.counters = new int[lhs.cSize];
    result.cSize = lhs.cSize;
    result.counters[0] = 0;
    for (int i = 1; i < result.cSize; ++i) {
        int leftCounters = lhs.counters[i] - lhs.counters[i - 1];
        int rightCounters = rhs.counters[i] - rhs.counters[i - 1];
        int rowCounter = 0;
        for (int j = 0; j < result.cSize - 1; ++j) {
            bool isMade = false;
            for (int k = 0; k < leftCounters; ++k) {
                if (lhs.indeces[k + lhs.counters[i - 1]] == j && lhs.values[k + lhs.counters[i - 1]] != 0) {
                    isMade = true;
                    enlarge_matrix(result.values, result.indeces, result.viSize);
                    ++rowCounter;
                    result.values[result.viSize - 1] = lhs.values[k + lhs.counters[i - 1]];
                    result.indeces[result.viSize - 1] = j;
                }
            }
            for (int k = 0; k < rightCounters; ++k) {
                if (rhs.indeces[k + rhs.counters[i - 1]] == j && rhs.values[k + rhs.counters[i - 1]] != 0) {
                    if (isMade) {
                        result.values[result.viSize - 1] += rhs.values[k + rhs.counters[i - 1]];
                        result.indeces[result.viSize - 1] = j;
                    }
                    else {
                        enlarge_matrix(result.values, result.indeces, result.viSize);
                        ++rowCounter;
                        result.values[result.viSize - 1] = rhs.values[k + rhs.counters[i - 1]];
                        result.indeces[result.viSize - 1] = j;
                    }
                }
            }
            result.values[result.viSize - 1];
        }
        result.counters[i] = result.counters[i - 1] + rowCounter;
    }
    return result;
}

// Оператор умножения матриц.
Matrix operator*(Matrix lhs, Matrix rhs) {
    rhs.transposition();
    Matrix result;
    result.cSize = lhs.cSize;
    result.counters = new int[lhs.cSize];
    result.counters[0] = 0;
    for (int i = 1; i < result.cSize; ++i) {
        int leftRowCounter = lhs.counters[i] - lhs.counters[i - 1];
        int* leftValues = new int[leftRowCounter];
        int* leftIndeces = new int[leftRowCounter];
        for (int j = 0; j < leftRowCounter; ++j) {
            leftValues[j] = lhs.values[j + lhs.counters[i - 1]];
            leftIndeces[j] = lhs.indeces[j + lhs.counters[i - 1]];
        }
        int rowCounter = 0;
        for (int j = 1; j < result.cSize; ++j) {
            int rightRowCounter = rhs.counters[i] - rhs.counters[i - 1];
            int* rightValues = new int[rightRowCounter];
            int* rightIndeces = new int[rightRowCounter];
            for (int k = 0; k < rightRowCounter; ++k) {
                rightValues[k] = rhs.values[k + rhs.counters[j - 1]];
                rightIndeces[k] = rhs.indeces[k + rhs.counters[j - 1]];
            }
            int newElement = 0;
            for (int l = 0; l < leftRowCounter; ++l) {
                for (int r = 0; r < rightRowCounter; ++r) {
                    if (leftIndeces[l] == rightIndeces[r]) {
                        newElement += leftValues[l] * rightValues[r];
                    }
                }
            }
            if (newElement != 0) {
                enlarge_matrix(result.values, result.indeces, result.viSize);
                ++rowCounter;
                result.values[result.viSize - 1] = newElement;
                result.indeces[result.viSize - 1] = j - 1;
            }
            delete[] rightValues;
            delete[] rightIndeces;
        }
        result.counters[i] = result.counters[i - 1] + rowCounter;
        delete[] leftValues;
        delete[] leftIndeces;
    }
    return result;
}

int main() {
    char fChoice, sChoice;
    Matrix matrix;
    cout << "Select INPUT method:\n\t1. Console input;\n\t2. File input.\nJust enter 1 or 2 here: ";
    cin >> fChoice;
    cout << "\nSelect OUTPUT method:\n\t1. Console output;\n\t2. File output.\nJust enter 1 or 2 here: ";
    cin >> sChoice;

    if (fChoice == '1') {
        cout << "\nInput number of vertices, number of edges and than edges: ";
        cin >> matrix;
    }
    else if (fChoice == '2') {
        // Открываем поток.
        ifstream fin("input.txt");
        if (fin) {
            fin >> matrix;
            // Закрываем поток.
            fin.close();
        }
        else
            cout << "Error: file is not opened.";
    }

    if (sChoice == '1') {
        cout << "\nAdjacency matrix:\n";
        cout << matrix;
        cout << "\nReachability matrix:\n";
        cout << matrix.create_reach_matrix();
    }
    else if (sChoice == '2') {
        // Обнуляем файл или создаём его, если его нет.
        ofstream new_fout("output.txt"); new_fout.close();
        // Открываем поток.
        ofstream fout("output.txt", ios_base::app);
        if (fout) {
            fout << "\nAdjacency matrix:\n";
            fout << matrix;
            fout << "\nReachability matrix:\n";
            fout << matrix.create_reach_matrix();
            fout.close();
        }
    }
    return 0;
}
