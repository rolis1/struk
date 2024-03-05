#include <iostream>
#include <string>
using namespace std;

const int maxBarang = 100; // Batas maksimal barang
const int maxTgl = 31; // Batas maksimal tanggal


struct barang {
    string nama;
    int jumlah;
    string kode;
    int tanggal;

};

void garis() {
    for(int i = 0; i < 60; i++) {
        cout << "=";
    }
}

void input(barang daftarBarang[][maxTgl], int& jmlBarang, int& jmlTgl) {
    cout << "Program Data Barang" << endl;
    cout << "Masukkan jumlah barang: ";
    cin >> jmlBarang;
    cout << "Masukkan jumlah tanggal terakhir: ";
    cin >> jmlTgl;

    while (jmlTgl < 5) {
        cout << "Jumlah tanggal yang Anda masukkan terlalu sedikit." << endl;
        cout << "Masukkan kembali jumlah tanggal terakhir: ";
        cin >> jmlTgl;
    }

    // Memasukkan data barang
    for (int tgl = 1; tgl <= jmlTgl; tgl++) {
        for (int i = 0; i < jmlBarang; i++) {
            cout << "Masukkan nama barang ke-" << i+1 
            << " untuk tanggal " << tgl << ": ";
            cin >> daftarBarang[i][tgl].nama;
            cout << "Masukkan jumlah barang ke-" << i+1 
            << " untuk tanggal " << tgl << ": ";
            cin >> daftarBarang[i][tgl].jumlah;
            cout << "Masukkan kode barang ke-" << i+1 
            << " untuk tanggal " << tgl << ": ";
            cin >> daftarBarang[i][tgl].kode;
            // Set tanggal
            daftarBarang[i][tgl].tanggal = tgl;
            cout << endl;
        }
    }
}

void output(barang daftarBarang[][maxTgl], int jmlBarang, int jmlTgl) {
    cout << "\nData Barang:" << endl;
    garis();
    cout << "\nNama\t\tJumlah\t\tKode\t\tTanggal\t\tAlamat" << endl;
    garis();
    cout << endl;
    for (int tgl = 1; tgl <= jmlTgl; tgl++) {
        for (int i = 0; i < jmlBarang; i++) {
            cout << daftarBarang[i][tgl].nama 
            << "\t\t" << daftarBarang[i][tgl].jumlah 
            << "\t\t" << daftarBarang[i][tgl].kode << "\t\t" 
            << daftarBarang[i][tgl].tanggal << "\t\t" 
            << &daftarBarang[i][tgl] << endl;
        }
    }
}

void cariData(barang daftarBarang[][maxTgl], int jmlBarang, int jmlTgl) {
    int tanggalCari;
    string kodeCari;
    cout << "\nMasukkan tanggal barang yang ingin Anda cari: ";
    cin >> tanggalCari;
    cout << "Masukkan kode barang yang ingin Anda cari: ";
    cin >> kodeCari;

    if (tanggalCari < 1 || tanggalCari > jmlTgl) {
        cout << "Tanggal yang dimasukkan tidak valid." << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < jmlBarang; i++) {
        if (daftarBarang[i][tanggalCari].kode == kodeCari) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama Barang: " << daftarBarang[i][tanggalCari].nama << endl;
            cout << "Jumlah Barang: " << daftarBarang[i][tanggalCari].jumlah << endl;
            cout << "Kode Barang: " << daftarBarang[i][tanggalCari].kode << endl;
            cout << "Tanggal Barang: " << daftarBarang[i][tanggalCari].tanggal << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Data barang tidak ditemukan." << endl;
    }
}

void menu(barang daftarBarang[][maxTgl], int& jmlBarang, int& jmlTgl) {
    int pil;
    cout << "Program Data Barang" << endl;
    garis();
    cout << "\n\tSelamat Datang di Program Data Barang" << endl;
    garis();
    cout << "\n\t\tPilihan Menu" << endl;

    cout << " 1. Input Barang Baru" << endl;
    cout << " 2. Cari Barang berdasarkan Tanggal dan Kode" << endl;
    cout << " 3. Tampilkan Semua Data Barang" << endl;
    cout << " 4. Keluar" << endl;

    cout << "Masukkan Pilihan: ";
    cin >> pil;

    system("cls");
    
    switch(pil) {
        case 1 : 
            input(daftarBarang, jmlBarang, jmlTgl);
            break;
        case 2 : 
            cariData(daftarBarang, jmlBarang, jmlTgl);
            break;
        case 3 : 
            output(daftarBarang, jmlBarang, jmlTgl);
            break;
        case 4 : 
            cout << "Program berakhir. Terima kasih!" << endl;
            exit(0);
            break;
        default :
            cout << "Pilihan tidak valid." << endl;
            break;
    }
}

int main() {
    barang daftarBarang[maxBarang][maxTgl];
    int jmlBarang = 0;
    int jmlTgl = 0;
    int tgl;

    while (true) {
        menu(daftarBarang, jmlBarang, jmlTgl);
    }

    cout << "Program ini dibuat oleh: Rolis Liu" << endl;
    cout << "NPM: 2310631170117" << endl;

    return 0;
}
