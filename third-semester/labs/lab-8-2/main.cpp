#include <fstream>
#include <string>

using namespace std;

template <class T>
class Node {
public:
    T key;
    T data;
    Node *next;
    Node *previous;

    Node() {
        next = NULL;
        previous = NULL;
    }

    Node(T k, T d) {
        key = k;
        data = d;
    }
};

template <class T>
class ListDL {
public:
    Node<T> *head;

    ListDL() {
        head = NULL;
    }
    ListDL(Node<T> *n) {
        head = n;
    }

    // Проверка существования узла по ключу
    Node<T> *node_exists(T k) {
        Node<T> *temp = NULL;
        Node<T> *ptr = head;

        while (ptr != NULL) {
            if (ptr->key == k) {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void push_back(Node<T> *n) {
        if (node_exists(n->key) != NULL) {}
        else {
            if (head == NULL) {
                head = n;
            }
            else {
                Node<T> *ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
            }
        }
    }

    // Вставка спереди
    void push_front(Node<T> *n) {
        if (node_exists(n->key) != NULL) {}
        else {
            if (head == NULL) {
                head = n;
          }
          else {
                head->previous = n;
                n->next = head;
                head = n;
            }
        }
    }

    // Вставка после выбранного элемента
    void insert(T k, Node<T> *n) {
        Node<T> *ptr = node_exists(k);
        if (ptr == NULL) {} 
        else {
            if (node_exists(n->key) != NULL) {} 
            else {
                Node<T> *nextNode = ptr->next;
                // вставка в конец
                if (nextNode == NULL) {
                    ptr->next = n;
                    n->previous = ptr;
                }
                // вставка внутри
                else {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                }
            }
        }
    }

    // Удаление узла по ключу
    void remove_node(T k) {
        Node<T> *ptr = node_exists(k);
        if (ptr == NULL) {
        } 
        else {
            if (head->key == k) {
                head = head->next;
            } 
            else {
                Node<T> *nextNode = ptr->next;
                Node<T> *prevNode = ptr->previous;
                // удаление в конце
                if (nextNode == NULL) {
                    prevNode->next = NULL;
                }
                // удаление внутри
                else {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                }
            }
        }
    }

    // Вывод
    void print_list() {
        ofstream fout("LR_8_2.txt", ios_base::app);
        if (head == NULL) {
            fout << "\nNo Nodes in Doubly Linked List";
        } else {
            fout << endl << "\nDoubly Linked List Values : ";
            Node<T> *temp = head;

            while (temp != NULL) {
                fout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
        }
        fout.close();
    }
};

template <class T>
class Queue {
public:
    Node<T> *head;

    Queue() {
        head = NULL;
    }
    Queue(Node<T> *n) {
        head = n;
    }

    // Проверка существования узла по ключу
    Node<T> *node_exists(T k) {
        Node<T> *temp = NULL;
        Node<T> *ptr = head;

        while (ptr != NULL) {
            if (ptr->key == k) {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void push_back(Node<T> *n) {
        if (node_exists(n->key) != NULL) {
        }
        else {
            if (head == NULL) {
                head = n;
            }
            else {
                Node<T> *ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
            }
        }
    }

    // Удаление узла по ключу
    void remove_node(T k) {
        Node<T> *ptr = node_exists(k);
        if (ptr == NULL) {
        } 
        else {
            if (head->key == k) {
                head = head->next;
            } 
            else {
                Node<T> *nextNode = ptr->next;
                Node<T> *prevNode = ptr->previous;
                // удаление в конце
                if (nextNode == NULL) {
                    prevNode->next = NULL;
                    ptr = node_exists(prevNode->key);   
                    remove_node(prevNode->key);
                }
                // удаление внутри
                else {
                    prevNode->next = nextNode;
                    /*ptr = node_exists(prevNode->key);*/
                    remove_node(prevNode->key);
                    nextNode->previous = prevNode;
                }
            }
        }
    }

    // Вывод
    void print_list() {
        ofstream fout("LR_8_2.txt", ios_base::app);
        if (head == NULL) {
            fout << "\nQueue is empty";
        } else {
            fout << endl << "\nQueue Values: ";
            Node<T> *temp = head;

            while (temp != NULL) {
                fout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
        }
        fout.close();
    }
};

template <class T>
class Stack {
public:
    Node<T> *head;

    Stack() {
        head = NULL;
    }
    Stack(Node<T> *n) {
        head = n;
    }

    // Проверка существования узла по ключу
    Node<T> *node_exists(T k) {
        Node<T> *temp = NULL;
        Node<T> *ptr = head;

        while (ptr != NULL) {
            if (ptr->key == k) {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    void push_back(Node<T> *n) {
        if (head == NULL) {
            head = n;
        }
        else {
            Node<T> *ptr = head;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = n;
            n->previous = ptr;
        }
    }

    // Удаление узла по ключу
    void remove_node(T k) {
        Node<T> *ptr = node_exists(k);
            Node<T> *nextNode = ptr->next;
            Node<T> *prevNode = ptr->previous;
            if (head->key == k) {
                head = NULL;
            }
            else {
                // удаление в конце
                if (nextNode == NULL) {
                    prevNode->next = NULL;
                }
                // удаление внутри
                else {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    remove_node(nextNode->key);
            }
        }
    }

    // Вывод
    void print_list() {
        ofstream fout("LR_8_2.txt", ios_base::app);
        if (head == NULL) {
            fout << "\nStack is empty";
        } 
        else {
            Node<T> *temp = head;
            fout << endl << "\nStack Values: ";
            while (temp != NULL) {
                fout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
    }
        fout.close();
    }
};

int main() {
    ofstream new_fout("LR_8_2.txt"); new_fout.close();
    ofstream fout("LR_8_2.txt", ios_base::app);
    fout << "List<string>";
    fout.close();
    ListDL<string> list1;
    string key1, k1, data1;
    if (true) {
        Node<string> *n0 = new Node<string>();
        n0->key = "zero";
        n0->data = "Aa";
        list1.push_back(n0);
        Node<string> *n1 = new Node<string>();
        n1->key = "one";
        n1->data = "Bb";
        list1.push_back(n1);
        Node<string> *n2 = new Node<string>();
        n2->key = "two";
        n2->data = "Cc";
        list1.push_back(n2);
        Node<string> *n3 = new Node<string>();
        n3->key = "three";
        n3->data = "Dd";
        list1.push_back(n3);
        Node<string> *n4 = new Node<string>();
        n4->key = "four";
        n4->data = "Ee";
        list1.push_back(n4);
        Node<string> *n5 = new Node<string>();
        n5->key = "five";
        n5->data = "Ff";
        list1.push_back(n5);
        Node<string> *n6 = new Node<string>();
        n6->key = "six";
        n6->data = "Gg";
        list1.push_back(n6);
        Node<string> *n7 = new Node<string>();
        n7->key = "seven";
        n7->data = "Hh";
        list1.push_back(n7);
        Node<string> *n8 = new Node<string>();
        n8->key = "eight";
        n8->data = "Ii";
        list1.push_back(n8);
        Node<string> *n9 = new Node<string>();
        n9->key = "nine";
        n9->data = "Jj";
        list1.push_back(n9);
        Node<string> *n10 = new Node<string>();
        n10->key = "ten";
        n10->data = "Kk";
        list1.push_back(n10);
        list1.print_list();
        list1.remove_node("three");
        list1.print_list();
    }

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nList<int>";
    fout.close();
    ListDL<int> list2;
    int key2, data2;
    for (int i = 0; i <= 10; i++) {
        Node<int> *n11 = new Node<int>();
        n11->key = i;
        n11->data = i*i*i;
        list2.push_back(n11);
    }
    list2.print_list();
    list2.remove_node(3);
    list2.print_list();

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nList<double>";
    fout.close();
    ListDL<double> list3;
    double key3, data3;
    for (double d = 0; d <= 10; d++) {
        Node<double> *n3 = new Node<double>();
        n3->key = d;
        n3->data = d * 3.14;
        list3.push_back(n3);
    }
    list3.print_list();
    list3.remove_node(3. * 3.14);
    list3.print_list();

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\n\n\nQueue<string>";
    fout.close();
    Queue<string> queue1;
    if (true) {
        Node<string> *n0 = new Node<string>();
        n0->key = "zero";
        n0->data = "Aa";
        queue1.push_back(n0);
        Node<string> *n1 = new Node<string>();
        n1->key = "one";
        n1->data = "Bb";
        queue1.push_back(n1);
        Node<string> *n2 = new Node<string>();
        n2->key = "two";
        n2->data = "Cc";
        queue1.push_back(n2);
        Node<string> *n3 = new Node<string>();
        n3->key = "three";
        n3->data = "Dd";
        queue1.push_back(n3);
        Node<string> *n4 = new Node<string>();
        n4->key = "four";
        n4->data = "Ee";
        queue1.push_back(n4);
        Node<string> *n5 = new Node<string>();
        n5->key = "five";
        n5->data = "Ff";
        queue1.push_back(n5);
        Node<string> *n6 = new Node<string>();
        n6->key = "six";
        n6->data = "Gg";
        queue1.push_back(n6);
        Node<string> *n7 = new Node<string>();
        n7->key = "seven";
        n7->data = "Hh";
        queue1.push_back(n7);
        Node<string> *n8 = new Node<string>();
        n8->key = "eight";
        n8->data = "Ii";
        queue1.push_back(n8);
        Node<string> *n9 = new Node<string>();
        n9->key = "nine";
        n9->data = "Jj";
        queue1.push_back(n9);
        Node<string> *n10 = new Node<string>();
        n10->key = "ten";
        n10->data = "Kk";
        queue1.push_back(n10);
        queue1.print_list();
        queue1.remove_node("three");
        queue1.print_list();
    }

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nQueue<int>";
    fout.close();
    Queue<int> queue2;
    for (int i = 0; i <= 10; i++) {
        Node<int> *n11 = new Node<int>();
        n11->key = i;
        n11->data = i*i*i;
        queue2.push_back(n11);
    }
    queue2.print_list();
    queue2.remove_node(3);
    queue2.print_list();

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nQueue<double>";
    fout.close();
    Queue<double> queue3;
    for (double d = 0; d <= 10; d++) {
        Node<double> *n3 = new Node<double>();
        n3->key = d;
        n3->data = d * 3.14;
        queue3.push_back(n3);
    }
    queue3.print_list();
    queue3.remove_node(3.);
    queue3.print_list();


    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\n\n\nStack<string>";
    fout.close();
    Stack<string> stack1;
    if (true) {
        Node<string> *n0 = new Node<string>();
        n0->key = "zero";
        n0->data = "Aa";
        stack1.push_back(n0);
        Node<string> *n1 = new Node<string>();
        n1->key = "one";
        n1->data = "Bb";
        stack1.push_back(n1);
        Node<string> *n2 = new Node<string>();
        n2->key = "two";
        n2->data = "Cc";
        stack1.push_back(n2);
        Node<string> *n3 = new Node<string>();
        n3->key = "three";
        n3->data = "Dd";
        stack1.push_back(n3);
        Node<string> *n4 = new Node<string>();
        n4->key = "four";
        n4->data = "Ee";
        stack1.push_back(n4);
        Node<string> *n5 = new Node<string>();
        n5->key = "five";
        n5->data = "Ff";
        stack1.push_back(n5);
        Node<string> *n6 = new Node<string>();
        n6->key = "six";
        n6->data = "Gg";
        stack1.push_back(n6);
        Node<string> *n7 = new Node<string>();
        n7->key = "seven";
        n7->data = "Hh";
        stack1.push_back(n7);
        Node<string> *n8 = new Node<string>();
        n8->key = "eight";
        n8->data = "Ii";
        stack1.push_back(n8);
        Node<string> *n9 = new Node<string>();
        n9->key = "nine";
        n9->data = "Jj";
        stack1.push_back(n9);
        Node<string> *n10 = new Node<string>();
        n10->key = "ten";
        n10->data = "Kk";
        stack1.push_back(n10);
        stack1.print_list();
        stack1.remove_node("three");
        stack1.print_list();
    }

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nStack<int>";
    fout.close();
    Stack<int> stack2;
    for (int i = 0; i <= 10; i++) {
        Node<int> *n11 = new Node<int>();
        n11->key = i;
        n11->data = i*i*i;
        stack2.push_back(n11);
    }
    stack2.print_list();
    stack2.remove_node(3);
    stack2.print_list();

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nStack<double>";
    fout.close();
    Stack<double> stack3;
    for (double d = 0; d <= 10; d++) {
        Node<double> *n3 = new Node<double>();
        n3->key = d;
        n3->data = d * 3.14;
        stack3.push_back(n3);
    }
    stack3.print_list();
    stack3.remove_node(3.);
    stack3.print_list();

    return 0;
}