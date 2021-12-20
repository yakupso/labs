#ifndef LR_8_2
#define LR_8_2

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
            fout << endl << "\nDoubly Linked List Values:\n";
            Node<T> *temp = head;


            while (temp->next != NULL) {
                fout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
            fout << "(" << temp->key << ": " << temp->data << ")";
        }
        fout.close();
    }
};

template <class T>
class myQueue {
public:
    Node<T> *head;

    myQueue() {
        head = NULL;
    }
    myQueue(Node<T> *n) {
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
            fout << "\nmyQueue is empty";
        } else {
            fout << endl << "\nmyQueue Values:\n";
            Node<T> *temp = head;

            while (temp->next != NULL) {
                fout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
            fout << "(" << temp->key << ": " << temp->data << ")";
        }
        fout.close();
    }
};

template <class T>
class myStack {
public:
    Node<T> *head;

    myStack() {
        head = NULL;
    }
    myStack(Node<T> *n) {
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
            fout << "\nmyStack is empty";
        } 
        else {
            Node<T> *temp = head;
            fout << endl << "\nmyStack Values:\n";
            while (temp->next != NULL) {
                fout << "(" << temp->key << ": " << temp->data << ") <=> ";
                temp = temp->next;
            }
            fout << "(" << temp->key << ": " << temp->data << ")";
    }
        fout.close();
    }
};

#endif // LR_8_2

/*int main() {
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
    fout << "\n\n\n\n\nmyQueue<string>";
    fout.close();
    myQueue<string> myqueue1;
    if (true) {
        Node<string> *n0 = new Node<string>();
        n0->key = "zero";
        n0->data = "Aa";
        myqueue1.push_back(n0);
        Node<string> *n1 = new Node<string>();
        n1->key = "one";
        n1->data = "Bb";
        myqueue1.push_back(n1);
        Node<string> *n2 = new Node<string>();
        n2->key = "two";
        n2->data = "Cc";
        myqueue1.push_back(n2);
        Node<string> *n3 = new Node<string>();
        n3->key = "three";
        n3->data = "Dd";
        myqueue1.push_back(n3);
        Node<string> *n4 = new Node<string>();
        n4->key = "four";
        n4->data = "Ee";
        myqueue1.push_back(n4);
        Node<string> *n5 = new Node<string>();
        n5->key = "five";
        n5->data = "Ff";
        myqueue1.push_back(n5);
        Node<string> *n6 = new Node<string>();
        n6->key = "six";
        n6->data = "Gg";
        myqueue1.push_back(n6);
        Node<string> *n7 = new Node<string>();
        n7->key = "seven";
        n7->data = "Hh";
        myqueue1.push_back(n7);
        Node<string> *n8 = new Node<string>();
        n8->key = "eight";
        n8->data = "Ii";
        myqueue1.push_back(n8);
        Node<string> *n9 = new Node<string>();
        n9->key = "nine";
        n9->data = "Jj";
        myqueue1.push_back(n9);
        Node<string> *n10 = new Node<string>();
        n10->key = "ten";
        n10->data = "Kk";
        myqueue1.push_back(n10);
        myqueue1.print_list();
        myqueue1.remove_node("three");
        myqueue1.print_list();
    }

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nmyQueue<int>";
    fout.close();
    myQueue<int> myqueue2;
    for (int i = 0; i <= 10; i++) {
        Node<int> *n11 = new Node<int>();
        n11->key = i;
        n11->data = i*i*i;
        myqueue2.push_back(n11);
    }
    myqueue2.print_list();
    myqueue2.remove_node(3);
    myqueue2.print_list();

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nmyQueue<double>";
    fout.close();
    myQueue<double> myqueue3;
    for (double d = 0; d <= 10; d++) {
        Node<double> *n3 = new Node<double>();
        n3->key = d;
        n3->data = d * 3.14;
        myqueue3.push_back(n3);
    }
    myqueue3.print_list();
    myqueue3.remove_node(3.);
    myqueue3.print_list();


    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\n\n\nmyStack<string>";
    fout.close();
    myStack<string> mystack1;
    if (true) {
        Node<string> *n0 = new Node<string>();
        n0->key = "zero";
        n0->data = "Aa";
        mystack1.push_back(n0);
        Node<string> *n1 = new Node<string>();
        n1->key = "one";
        n1->data = "Bb";
        mystack1.push_back(n1);
        Node<string> *n2 = new Node<string>();
        n2->key = "two";
        n2->data = "Cc";
        mystack1.push_back(n2);
        Node<string> *n3 = new Node<string>();
        n3->key = "three";
        n3->data = "Dd";
        mystack1.push_back(n3);
        Node<string> *n4 = new Node<string>();
        n4->key = "four";
        n4->data = "Ee";
        mystack1.push_back(n4);
        Node<string> *n5 = new Node<string>();
        n5->key = "five";
        n5->data = "Ff";
        mystack1.push_back(n5);
        Node<string> *n6 = new Node<string>();
        n6->key = "six";
        n6->data = "Gg";
        mystack1.push_back(n6);
        Node<string> *n7 = new Node<string>();
        n7->key = "seven";
        n7->data = "Hh";
        mystack1.push_back(n7);
        Node<string> *n8 = new Node<string>();
        n8->key = "eight";
        n8->data = "Ii";
        mystack1.push_back(n8);
        Node<string> *n9 = new Node<string>();
        n9->key = "nine";
        n9->data = "Jj";
        mystack1.push_back(n9);
        Node<string> *n10 = new Node<string>();
        n10->key = "ten";
        n10->data = "Kk";
        mystack1.push_back(n10);
        mystack1.print_list();
        mystack1.remove_node("three");
        mystack1.print_list();
    }

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nmyStack<int>";
    fout.close();
    myStack<int> mystack2;
    for (int i = 0; i <= 10; i++) {
        Node<int> *n11 = new Node<int>();
        n11->key = i;
        n11->data = i*i*i;
        mystack2.push_back(n11);
    }
    mystack2.print_list();
    mystack2.remove_node(3);
    mystack2.print_list();

    fout.open("LR_8_2.txt", ios_base::app);
    fout << "\n\n\nmyStack<double>";
    fout.close();
    myStack<double> mystack3;
    for (double d = 0; d <= 10; d++) {
        Node<double> *n3 = new Node<double>();
        n3->key = d;
        n3->data = d * 3.14;
        mystack3.push_back(n3);
    }
    mystack3.print_list();
    mystack3.remove_node(3.);
    mystack3.print_list();

    return 0;
}*/