#include <iostream>
#include <cstdlib>
using namespace std;

#define SIZE 10

template <class T>
class Queue {
    T *arr;         // массив для хранения элементов очереди
    int capacity;   // максимальная вместимость
    int front;      // указывает на передний элемент в очереди (если такой существует)
    int rear;       // указывает на задний элемент
    int count;      // текущий размер очереди
public:
    Queue(int size = SIZE);
    void remove();
    void add(T x);
    T front_elem();
    int size();
    bool is_empty();
    bool is_full();
    void print_queue();
};

// Инициализация очереди
template <class T>
Queue<T>::Queue(int size) {
    arr = new T[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Вспомогательная функция удаления переднего элемента
template <class T>
void Queue<T>::remove() {
    // проверка на пустоту
    if (is_empty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    cout << "Removing " << arr[front] << endl;
    front = (front + 1) % capacity;
    count--;
}

// Добавление элемента в очередь
template <class T>
void Queue<T>::add(T item) {
    // проверка переполненности
    if (is_full()) {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// Вспомогательная функция, возвращающая передний элемент очереди
template <class T>
T Queue<T>::front_elem() {
    if (is_empty()) {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// текущий размер
template <class T>
int Queue<T>::size() {
    return count;
}

// проверка на пустоту
template <class T>
bool Queue<T>::is_empty() {
    return (size() == 0);
}

// проверка на заполненность
template <class T>
bool Queue<T>::is_full() {
    return (size() == capacity);
}

template <class T>
void Queue<T>::print_queue() {
    int s = size();
    cout << "\nQueue: ";
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    cout << endl;  
}

int main() {
    int def_choice;
    Queue<int> obj_int(5);
    Queue<double> obj_double(5);
    Queue<string> obj_str(5);

    cout << "Integers:\n";
    obj_int.add(1);
    obj_int.add(2);
    obj_int.add(3);
    obj_int.add(4);
    obj_int.add(5);
    obj_int.print_queue();
    cout << "The front element is " << obj_int.front_elem() << endl;
    while (!obj_int.is_empty()) {
        obj_int.remove();
    }
    cout << endl;

    cout << "Doubles:\n";
    obj_double.add(1.1);
    obj_double.add(2.2);
    obj_double.add(3.3);
    obj_double.add(4.4);
    obj_double.add(5.5);
    obj_double.print_queue();
    cout << "The front element is " << obj_double.front_elem() << endl;
    while (!obj_double.is_empty()) {
        obj_double.remove();
    }
    cout << endl;

    cout << "Strings:\n";
    obj_str.add("one");
    obj_str.add("two");
    obj_str.add("three");
    obj_str.add("four");
    obj_str.add("five");
    obj_str.print_queue();
    cout << "The front element is " << obj_str.front_elem() << endl;
    while (!obj_str.is_empty()) {
        obj_str.remove();
    }
    cout << endl;

    return 0;
}