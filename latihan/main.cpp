#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;


struct alamatMahasiswa {
    string kota;
    string kecamatan;
    int kodepos;
};

struct mahasiswa {
    alamatMahasiswa alamat;
    string npm;
    string nama;
    float ipk;
};

int main () {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa : ";
    cin >> jumlah;

    mahasiswa mhs[jumlah];

    for ( int i = 0; i < jumlah; i++) {
        cout << "Masukkan data mahasiswa ke-" << i+1 << endl;
        cout << "Masukkan nama\t\t: ";
        cin >> mhs[i].nama;
        cout << "Masukkan NPM\t\t: ";
        cin >> mhs[i].npm;
        cout << "Masukkan alamat\t\t: "<< endl;
        cout << "Masukkan kota\t\t: ";
        cin >> mhs[i].alamat.kota;
        cout << "Masukkan kecamatan\t\t: ";
        cin >> mhs[i].alamat.kecamatan;
        cout << "Masukkan kodepos\t\t: ";
        cin >> mhs[i].alamat.kodepos;
        cout << "Masukkan nilai IPK\t: ";
        cin >> mhs[i].ipk;
    }

system("cls");

    cout << "Nama" << endl;

    cout << "Data Mahasiswa" << endl;
    for (int i = 0; i < jumlah; i ++) {
        cout << setiosflags(ios::left) << setw(11) << mhs[i].nama;
        cout << setiosflags(ios::left) << setw(12) << mhs[i].npm;
        cout << setiosflags(ios::left) << setw(14) << mhs[i].alamat.kota;
        cout << setiosflags(ios::left) << setw(16) << mhs[i].alamat.kecamatan;
        cout << setiosflags(ios::left) << setw(16) << mhs[i].alamat.kodepos;
        cout << setiosflags(ios::left) << setw(4) << mhs[i].ipk;
    }

    return 0;
}