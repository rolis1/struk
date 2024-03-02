#include <iostream>
using namespace std;

int main () {
    int btsSiswa;
    string jmlSiswa[btsSiswa];

        cout << "Masukkan Jumlah Siswa : "; 
        cin >> btsSiswa;
    
    for ( int i = 0; i < btsSiswa; i++) {
        cout << "Masukkan data siswa ke-" << i+1 << " : ";
        cin >> jmlSiswa[i];
    }

cout << "\nNama Siswa\tAlamat pada komputer" << endl;
cout << "======================================\n";

    for ( int j = 0; j < btsSiswa; j++) {
        cout << jmlSiswa[j] << "\t\t" << &jmlSiswa[j] << endl;
    }

    cout << "\nProgram ini dibuat oleh : Rolis Liu" << endl;
    cout << "NPM : 2310631170117" << endl;

}