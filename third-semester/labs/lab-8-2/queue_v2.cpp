#include <iostream>
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
            cout << "Node Already exists with key value : " << n->key
                    << ". Append another node with different Key value" << endl;
        }
        else {
            if (head == NULL) {
                head = n;
                cout << "Node Appended as Head Node" << endl;
            }
            else {
                Node<T> *ptr = head;
                while (ptr->next != NULL) {
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Appended" << endl;
            }
        }
    }

    // Удаление узла по ключу
    void remove_node(T k) {
        Node<T> *ptr = node_exists(k);
        if (ptr == NULL) {
            cout << "No node exists with key value: " << k << endl;
        } 
        else {
            if (head->key == k) {
                head = head->next;
                cout << "Node deleted and now queue empty"<< endl;
            } 
            else {
                Node<T> *nextNode = ptr->next;
                Node<T> *prevNode = ptr->previous;
                // удаление в конце
                if (nextNode == NULL) {
                    prevNode->next = NULL;
                    ptr = node_exists(prevNode->key);   
                    remove_node(prevNode->key);
                    cout << "Node Deleted at the END" << endl;
                }
                // удаление внутри
                else {
                    prevNode->next = nextNode;
                    /*ptr = node_exists(prevNode->key);*/
                    remove_node(prevNode->key);
                    nextNode->previous = prevNode;
                    cout << "Node Deleted in Between" << endl;
                }
            }
        }
    }

    // Вывод
    void print_list() {
        if (head == NULL) {
            cout << "Queue is empty";
        } else {
            cout << endl << "Queue Values: ";
            Node<T> *temp = head;

            while (temp != NULL) {
                cout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
        }
    }
};

int main() {
    int def_choice = -1;
    Queue<string> obj;
    string key1, k1, data1;
    while (def_choice != 0) {
        cout << "\nEnter option number (0 to exit)." << endl;
        cout << "1. push_back()" << endl;
        cout << "2. remove_node()" << endl;
        cout << "3. print_list()" << endl;
        cin >> def_choice;
        Node<string> *n1 = new Node<string>();

        switch (def_choice) {
            case 0: {
                break;
            }
            case 1: {
                cout << "Push back operation\n"
                    << "Enter key & data of the node to be pushed back:\n";
                cin >> key1;
                cin >> data1;
                n1->key = key1;
                n1->data = data1;
                obj.push_back(n1);
                break;
            }
            case 2: {
                cout << "Remove node operation\n" 
                    << "Enter key of the node to be deleted:\n";
                cin >> k1;
                obj.remove_node(k1);
                break;
            }
            case 3: {
                obj.print_list();
                break;
            }
            default: {
                cout << "Error: Invalid value!" << endl;
            }
        }
    }
    return 0;
}