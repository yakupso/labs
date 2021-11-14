#include <iostream>
#include <cmath>
using namespace std;

double average(int a, int b, int c, int d){
    double t , e;
    t = a + b + c + d;
    e = t/4;
    return e;
}

int max(int a, int b, int c, int d){
    int maximum = a;

        if (b >  maximum)
             maximum = b;
        if (c >  maximum)
             maximum = c;
        if (d >  maximum)
             maximum = d;
        return  maximum;
}

int div(int a, int b, int c, int d){
    int minr;
    minr = abs(a - b);
    if (abs(a-c)<minr)
        minr = abs(a - c);
    if (abs(a-d)<minr)
        minr = abs(a - d);
    if (abs(b-c)<minr)
        minr = abs(b - c);
    if (abs(b-d)<minr)
        minr = abs(b-d);
    if (abs(c-d)<minr)
        minr = abs(c-d);
    return minr;

}
void fibonacci(int num, int nBegin){
    int first = 1, second = 1;
    int temp;

    cout << "\nOutput: ";

    for(int i = 3; i <= nBegin; i++){
        temp = first;
        first = second;
        second += temp;
    }

    for (int i = nBegin +1; i <= nBegin + num; i++){
        temp = first;
        first = second;
        second += temp;
        cout << first << ' ';
    }
    cout << "\n";
}


