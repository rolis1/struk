#include <iostream>
#include <iomanip>
#include <cstring>  // untuk memanggil strcmp
using namespace std;

void garis() {
    for(int i = 0; i < 60; i++) {
        cout << "=";
    }
}

struct Nilai { // struct untuk menyimpan data nilai-nilai mahasiswa
    float nilaiAbsen, nilaiTugas, nilaiUTS, nilaiUAS, nilaiAkhir;
    char indexHuruf;
};

struct mahasiswa { // struct untuk menyimpan data mahasiswa
    char nama[50];
    char npm[13];
    struct Nilai nilai;
};


char hitungIndex(float nIndexAkhir) {
    if (nIndexAkhir > 80) return 'A';
    else if (nIndexAkhir > 70) return 'B';
    else if (nIndexAkhir > 60) return 'C';
    else return 'D';
}

// fungsi untuk menampilkan data mahasiswa
void tampilData(struct mahasiswa dataMahasiswa[], int jumlahData) {
    cout << "===============================================================================\n";
    cout << "| " << setw(15) << "NPM" << " | " << setw(10) << "Nama" << " | " 
        << setw(10) << "Nilai Absen" 
        << " | " << setw(10) << "Nilai Tugas" << " | " << setw(10) << "Nilai UTS" << " | "
        << setw(10) << "Nilai UAS" << " | " << setw(12) << "Nilai Akhir" << " | " << setw(12)
        << "Nilai Huruf"
        << " |\n";
    cout << "===============================================================================\n";
    for (int i = 0; i < jumlahData; i++) {
        cout << "| " << setw(15) << dataMahasiswa[i].npm << " | " 
            << setw(10) << dataMahasiswa[i].nama << " | " 
            << setw(12) << dataMahasiswa[i].nilai.nilaiAbsen << " | "
            << setw(10) << dataMahasiswa[i].nilai.nilaiTugas << " | "
            << setw(10) << dataMahasiswa[i].nilai.nilaiUTS << " | "
            << setw(10) << dataMahasiswa[i].nilai.nilaiUAS << " | "
            << setw(10) << dataMahasiswa[i].nilai.nilaiAkhir << " | "
            << setw(10) << dataMahasiswa[i].nilai.indexHuruf << " |\n";
    }
    cout << "===============================================================================\n";
}
int pil;

int main() {
    struct mahasiswa dataMahasiswa[20];
    int jumlahData = 0;
    char pilihan;

    do {
        cout << "Program Data Mahasiswa" << endl;
        garis();
        cout << "\n\tSelamat Datang di Program Data Mahasiswa" << endl;
        garis();
        cout << "\n\t\tPilihan Menu" << endl;
        cout << "1. Input Data Mahasiswa\n";
        cout << "2. Tampil Data Mahasiswa\n";
        cout << "3. Edit Data Mahasiswa\n";
        cout << "4. Hapus Data Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pil;

        switch (pil) {
            case 1: // input data mahasiswa
                cout << "Masukkan data mahasiswa:\n";
                cout << "NPM: ";
                cin >> dataMahasiswa[jumlahData].npm;
                cout << "Nama: ";
                /**cin ignore, clear baris baru dan berfungsi untuk 
                memberikan kata lebih dari 1**/
                cin.ignore(); 
                cin.getline(dataMahasiswa[jumlahData].nama, 50);
                cout << "Nilai Absen: ";
                cin >> dataMahasiswa[jumlahData].nilai.nilaiAbsen;
                cout << "Nilai Tugas: ";
                cin >> dataMahasiswa[jumlahData].nilai.nilaiTugas;
                cout << "Nilai UTS: ";
                cin >> dataMahasiswa[jumlahData].nilai.nilaiUTS;
                cout << "Nilai UAS: ";
                cin >> dataMahasiswa[jumlahData].nilai.nilaiUAS;

                // menentukan nilai akhir dan index huruf
                dataMahasiswa[jumlahData].nilai.nilaiAkhir 
                = 0.1 * dataMahasiswa[jumlahData].nilai.nilaiAbsen + 
                0.2 * dataMahasiswa[jumlahData].nilai.nilaiTugas + 
                0.3 * dataMahasiswa[jumlahData].nilai.nilaiUTS + 
                0.4 * dataMahasiswa[jumlahData].nilai.nilaiUAS;
                dataMahasiswa[jumlahData].nilai.indexHuruf = 
                hitungIndex(dataMahasiswa[jumlahData].nilai.nilaiAkhir);

                jumlahData++;
                break;

            case 2 :
                // menampilkan data mahasiswa
                if (jumlahData > 0) {
                    tampilData(dataMahasiswa, jumlahData);
                } else {
                    cout << "Belum ada data mahasiswa.\n";
                }
                break;

            case 3 :
                // mengedit data mahasiswa
                if (jumlahData > 0) {
                    char npmCari[15];
                    cout << "Masukkan NPM mahasiswa yang ingin diedit: ";
                    cin >> npmCari;

                    int index = -1;
                    for (int i = 0; i < jumlahData; i++) {
                        if (strcmp(dataMahasiswa[i].npm, npmCari) == 0) {
                            index = i;
                            break;
                        }
                    }

                    if (index != -1) {
                        cout << "Masukkan data mahasiswa baru:\n";
                        cout << "Nama: ";
                        cin.ignore();
                        cin.getline(dataMahasiswa[index].nama, 50);
                        cout << "Nilai Absen: ";
                        cin >> dataMahasiswa[index].nilai.nilaiAbsen;
                        cout << "Nilai Tugas: ";
                        cin >> dataMahasiswa[index].nilai.nilaiTugas;
                        cout << "Nilai UTS: ";
                        cin >> dataMahasiswa[index].nilai.nilaiUTS;
                        cout << "Nilai UAS: ";
                        cin >> dataMahasiswa[index].nilai.nilaiUAS;

                        // menentukan nilai akhir dan nilai index
                        dataMahasiswa[index].nilai.nilaiAkhir = 
                        0.1 * dataMahasiswa[index].nilai.nilaiAbsen + 
                        0.2 * dataMahasiswa[index].nilai.nilaiTugas + 
                        0.3 * dataMahasiswa[index].nilai.nilaiUTS + 
                        0.4 * dataMahasiswa[index].nilai.nilaiUAS;
                        dataMahasiswa[index].nilai.indexHuruf = 
                        hitungIndex(dataMahasiswa[index].nilai.nilaiAkhir);

                        cout << "Data mahasiswa berhasil diubah!\n";
                    } else {
                        cout << "NPM tidak ditemukan!\n";
                    }
                } else {
                    cout << "Belum ada data mahasiswa.\n";
                }
                break;

            case 4 :
                // menu menghapus data mahasisaw
                if (jumlahData > 0) {
                    char npmHapus[15];
                    cout << "Masukkan NPM mahasiswa yang ingin dihapus: ";
                    cin >> npmHapus;

                    int indexHapus = -1;
                    for (int i = 0; i < jumlahData; i++) {
                        if (strcmp(dataMahasiswa[i].npm, npmHapus) == 0) {
                            indexHapus = i;
                            break;
                        }
                    }

                    if (indexHapus != -1) {
                        // geser data ke atas untuk menghapus data
                        for (int i = indexHapus; i < jumlahData - 1; i++) {
                            dataMahasiswa[i] = dataMahasiswa[i + 1];
                        }
                        jumlahData--;

                        cout << "Data mahasiswa berhasil dihapus!\n";
                    } else {
                        cout << "Data tidak ditemukan!\n";
                    }
                } else {
                    cout << "Belum ada data mahasiswa.\n";
                }
                break;

            case 5 :
                // keluar dari program
                cout << "Program berakhir. Terima Kasih^^.\n";
                cout << "Program ini dibuat oleh: Rolis Liu" << endl;
                cout << "NPM: 2310631170117" << endl;
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pil != 5);

    return 0;
}