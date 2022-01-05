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
        if (node_exists(n->key) != NULL) {
            fout << "\nNode Already exists with key value : " << n->key
                    << ". Append another node with different Key value" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                fout << "\nNode Appended as Head Node" << endl;
            }
            else {
                Node<T> *ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                fout << "Node Appended" << endl;
            }
        }
    }

    // Вставка спереди
    void push_front(Node<T> *n) {
        if (node_exists(n->key) != NULL) {
            fout << "\nNode Already exists with key value : " << n->key
                    << ". Append another node with different Key value" << endl;
        }
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
        if (ptr == NULL) {
            fout << "\nNo node exists with key value: " << k << endl;
        } 
        else {
            if (node_exists(n->key) != NULL) {
                fout << "\nNode Already exists with key value : " << n->key 
                        << ". Append another node with different Key value" << endl;
            } 
            else {
                Node<T> *nextNode = ptr->next;
                // вставка в конец
                if (nextNode == NULL) {
                    ptr->next = n;
                    n->previous = ptr;
                    fout << "\nNode Inserted at the END" << endl;
                }
                // вставка внутри
                else {
                    n->next = nextNode;
                    nextNode->previous = n;
                    n->previous = ptr;
                    ptr->next = n;
                    fout << "\nNode Inserted in Between" << endl;
                }
            }
        }
    }

    // Удаление узла по ключу
    void remove_node(T k) {
        Node<T> *ptr = node_exists(k);
        if (ptr == NULL) {
            fout << "\nNo node exists with key value: " << k << endl;
        } 
        else {
            if (head->key == k) {
                head = head->next;
                fout << "\nNode UNLINKED with keys value : " << k << endl;
            } 
            else {
                Node<T> *nextNode = ptr->next;
                Node<T> *prevNode = ptr->previous;
                // удаление в конце
                if (nextNode == NULL) {
                    prevNode->next = NULL;
                    fout << "\nNode Deleted at the END" << endl;
                }
                // удаление внутри
                else {
                    prevNode->next = nextNode;
                    nextNode->previous = prevNode;
                    fout << "\nNode Deleted in Between" << endl;
                }
            }
        }
    }

    // Вывод
    void print_list() {
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
    }
};


int main() {
    fout << "List<string>";
    ListDL<string> list1;
    string key1, k1, data1;
    Node<string> *n0 = new Node<string>();
    n0->key = "zero";
    n0->data = "Aa";
    list1.push_back(n0);
    Node<string> *n1 = new Node<string>();
    n1->key = "one";
    n1->data = "Bb";
    list1.push_back(n1);
    list1.print_list();

    fout << "\n\n\nList<int>";
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

    fout << "\n\n\nList<double>";
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
    
    return 0;
}
