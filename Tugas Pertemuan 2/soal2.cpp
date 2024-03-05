#include <iostream>
using namespace std;

const int maxSize = 100;

void rotateImage(int array[][maxSize], int n) {
    // Membalik elemen-elemen dalam matriks secara diagonal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            swap(array[i][j], array[j][i]);
        }
    }
    // Membalik setiap baris dalam matriks
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            swap(array[i][j], array[i][n - j - 1]);
        }
    }
}

int main() {
    int n;
    cout << "Masukkan ukuran matriks (n x n): ";
    cin >> n;

    // Meminta pengguna untuk memasukkan nilai matriks
    int array[maxSize][maxSize];
    cout << "Masukkan elemen-elemen matriks: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Element baris ke-" << i+1 << ": ";
            cin >> array[i][j];
        }
    }

    // Memutar gambar sebesar 90 derajat searah jarum jam
    rotateImage(array, n);

    // Menampilkan matriks yang sudah diputar
    cout <<
    "\nGambar yang sudah diputar 90 derajat searah jarum jam:" 
    << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
