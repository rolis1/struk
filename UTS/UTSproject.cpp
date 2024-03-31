#include <iostream>
#include <cstring>

using namespace std;

// deklarasi struct untuk menampung data kontak
struct Kontak {
    char nama[50];
    char nomorTelepon[15];
    Kontak* berikutnya;
};

// function untuk menambahkan kontak baru ke dalam linked list
void tambahKontak(Kontak*& kepala, const char* nama, const char* nomorTelepon) {
    Kontak* kontakBaru = new Kontak; // membuat node kontak baru
    strcpy(kontakBaru->nama, nama);
    strcpy(kontakBaru->nomorTelepon, nomorTelepon);
    kontakBaru->berikutnya = nullptr;

    // jika linked list kosong, atur kontak baru sebagai kepala
    if (kepala == nullptr) {
        kepala = kontakBaru;
        return;
    }

    // jika tidak, cari node terakhir dan tambahkan kontak baru
    Kontak* temp = kepala;
    while (temp->berikutnya != nullptr) {
        temp = temp->berikutnya;
    }
    temp->berikutnya = kontakBaru;
}

// function untuk menampilkan semua kontak dalam buku telepon
void tampilkanKontak(const Kontak* kepala) {
    cout << "Kontak:" << endl;
    while (kepala != nullptr) {
        cout << "Nama: " << kepala->nama << ", Nomor Telepon: " << kepala->nomorTelepon << endl;
        kepala = kepala->berikutnya;
    } cout << endl;
}   

// function untuk mencari kontak berdasarkan nama
void cariKontak(const Kontak* kepala, const char* nama) {
    const Kontak* temp = kepala;
    bool ditemukan = false;
    while (temp != nullptr) {
        if (strcmp(temp->nama, nama) == 0) {
            system("cls");
            cout << "Kontak ditemukan:" << endl;
            cout << "Nama: " << temp->nama << ", Nomor Telepon: " << temp->nomorTelepon << endl;
            ditemukan = true;
            break;
        }
        temp = temp->berikutnya;
    }
    if (!ditemukan) {
        system("cls");
        cout << "Kontak tidak ditemukan." << endl;
    }
}

int main() {
    Kontak* bukuTelepon = nullptr;

    // menambahkan beberapa kontak awal
    tambahKontak(bukuTelepon, "John Doe", "1234567890");
    tambahKontak(bukuTelepon, "Jane Smith", "0987654321");

    int pil;
    char nama[50];
    char nomorTelepon[15];

    do {
        cout << "Menu Buku Telepon:" << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Tampilkan Semua Kontak" << endl;
        cout << "3. Cari Kontak berdasarkan Nama" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan Anda: ";
        cin >> pil;

        switch (pil) {
            case 1:
                cout << "Masukkan nama: ";
                cin.ignore();
                cin.getline(nama, 50);
                cout << "Masukkan nomor telepon: ";
                cin.getline(nomorTelepon, 15);
                tambahKontak(bukuTelepon, nama, nomorTelepon);
                system("cls");
                break;
            case 2:
                system("cls");
                tampilkanKontak(bukuTelepon);
                break;
            case 3:
                cout << "Masukkan nama untuk dicari: ";
                cin.ignore();
                cin.getline(nama, 50);
                cariKontak(bukuTelepon, nama);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                cout << "Program ini dibuat oleh Rolis Liu" << endl;
                cout << "NPM: 2310631170117" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pil != 4);

    // Membebaskan memori yang dialokasikan untuk linked list
    while (bukuTelepon != nullptr) {
        Kontak* temp = bukuTelepon;
        bukuTelepon = bukuTelepon->berikutnya;
        delete temp;
    }

    return 0;
}
