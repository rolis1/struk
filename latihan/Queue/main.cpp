#include <iostream>
#define maks 20
using namespace std;
// mendeklarasi structure Queue
struct Queue
{
    int front, rear, data[maks];
} Q;
// Mengecek apakah queue penuh
bool isFull()
{
    return Q.rear == maks;
}
// mengecek apakah queue kosong
bool isEmpty()
{
    return Q.rear == 0;
}
// menampilkan queue
void printQueue()
{
    if (isEmpty())
    {
        cout << "Antrian masih kosong" << endl;
    }
    else
    {
        cout << "Queue : ";
        for (int i = Q.front; i < Q.rear; i++)
        {
            cout << Q.data[i] << ((Q.rear - 1 == i) ? " " : ",");
        }
        cout << endl;
    }
}
// enqueue
void enqueue()
{
    if (isFull())
    {
        cout << "Queue sudah penuh" << endl;
    }
    else
    {
        int data;
        cout << "Masukkan data : ";
        cin >> data;
        Q.data[Q.rear] = data;
        // Iterasi rear 
        Q.rear++;

        cout << "Data berhasil ditambahkan \n";
        printQueue();
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue masih kosong" << endl;
    }
    else
    {
        cout << "Mengeluarkan data | " << Q.data[Q.front] << " | \n";
        // Mengubah queue data ke head
        for (int i = Q.front; i < Q.rear; i++)
        {
            Q.data[i] = Q.data[i + 1];
        }
        Q.rear--;
        printQueue();
    }
}

int main()
{
    int pilih;
    do
    {
        // tampilkan menu
        cout << "===========\n";
        cout << " Menu Pilihan \n ";
        cout << "1. Enqueue(entry data) \n ";
        cout << "2. Dequeue(keluar data) \n ";
        cout << "3. Keluar(Quit) \n ";
        cout << "===========\n ";
        cout << "Masukkan pilihan : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            enqueue();
            cout << endl;
            cout << " Front : " << Q.front;
            cout << " Rear : " << Q.rear << endl;
            break;
        case 2:
            dequeue();
            cout << endl;
            cout << " Front : " << Q.front;
            cout << " Rear : " << Q.rear << endl;
            break;
        default:
            cout << "Pilihan tidak tersedia \n";
            break;
        }
    } while (pilih != 3);
    return 0;
}