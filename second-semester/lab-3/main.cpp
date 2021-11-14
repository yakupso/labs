#include <iostream>
#include "funcs.h"
using namespace std;

int main()
{
    int a, b, c, d;
    int num, nBegin;
    cout << "Choose an action : \n\t 1)Div \n\t 2)Max  \n\t 3)Average" << endl;
    int act;
    cin >> act ;
    switch (act) {
    case 1:
        cout << "Input a, b, c, d: ";
        cin >> a >> b >> c >> d;
        cout << div(a, b, c, d);
    break;
    case 2:
        cout << "Input a, b, c, d: ";
        cin >> a >> b >> c >> d;
        cout << max(a, b, c, d);
    break;
    case 3:
        cout << "Input a, b, c, d: ";
        cin >> a >> b >> c >> d;
        cout << average(a, b, c, d);
    break;
    case 4:
        cout << "Input num, nBegin: ";
        cin >> num >> nBegin;
        fibonacci(num, nBegin);
    break;

    default:
        cout << "Error";
    }

    return 0;
}
