#include <iostream>
using namespace std;

int main () {
    int matrixA[2][2];
    int matrixB[2][2];
    int matrixC[2][2];

    //nilai matrix A
    for (int i = 0; i < 2; i++) {
        for ( int j = 0; j < 2; j++) {
            cout << "Masukkan nilai untuk matrix A = [" << i << "][" << j << "] : ";
            cin >> matrixA[i][j];
        }
    }

    cout << "Matrix A : " << endl;

    for ( int i = 0; i < 2; i++) {
        for ( int j = 0; j < 2; j++) {
            cout << matrixA[i][j] << " ";
        }
        cout << endl;
    }

    //nilai matrix B
    for ( int i = 0; i < 2; i++) {
        for ( int j = 0; j < 2; j++) {
            cout << "Masukkan nilai untuk matrix B = [" << i <<"][" << j << "] : ";
            cin >> matrixB[i][j];
        }
    }

    cout << "Matrix B : " << endl;

    for ( int i = 0; i < 2; i++) {
        for ( int j = 0; j < 2; j++) {
            cout << matrixB[i][j] << " ";
        }
        cout << endl;
    }

    //penjujmlahan matrix

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matrixC[i][j] = 0; // Inisialisasi elemen matriks hasil dengan 0
            for (int k = 0; k < 2; k++) {
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    cout << "Hasil perkalian matriks A dan B adalah : " << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrixC[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}