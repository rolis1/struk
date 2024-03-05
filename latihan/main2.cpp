#include <iostream>
#define SIZE 6

typedef int multiplication[SIZE][SIZE];

using namespace std;

int main () {
    multiplication A;
    int* multiplied;

    multiplied = &A[0][0];

    for ( int i = 5; i <= 10; i++) {
        for( int j = 5; j <= 10; j++) {
            A[i-5][j-5] = i*j;
            cout << A[i-5][j-5] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << "Alamat array " << endl;
    for ( int i = 0; i < 6; i++) {
        for ( int j = 0; j < 6; j++) {
            cout << "Alamat tersimpan A[" << i << "][" << j << "] : " << multiplied << endl;
            multiplied++;
        }
    }
}