#include <iostream>
using namespace std;

const int n = 20;

void se(int *A)
{
    int *sA = new int[n+1];
    for (int i = 0; i <= n; i++)
        sA[i] = 0;
                                   // 0 0 0 0 0 0 0 0 0  0 0  0  0  0  0  0  0  0  0  0  0
    for (int i = 0; i < n; i++)    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        sA[A[i]]++;                

    cout << endl;
    for (int i = 0; i <= n; i++){
        cout << i << " - " << sA[i] << endl;
    }
}

int main()
{
    int *A = new int[n];
    for (int i = 0; i < n; i++){
        A[i] = rand() % 21;
        cout << A[i] << " ";
    }

    
    se(A);
    return 0;
}