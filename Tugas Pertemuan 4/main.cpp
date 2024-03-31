#include <iostream>
using namespace std;

struct node { //struktur yang menyimpan node
    int data; //nilai integer
    node *next; //menunjukan ke node selanjutnya
};

int main () {
    char ulang;

    do { /**untuk menanyakan apakah pengguna ingin 
    memasukkan angka baru setelah operasi selesai.**/
        node *head = 0;
        int a, data;

        system("cls");
        
        cout << "Masukkan jumlah angka: ";
        cin >> a;

        for (int i = 1; i <= a; i++) {
            cout << "Masukkan angka ke-" << i << ": ";
            cin >> data;
            // pointer
            node *newNode = new node;
            newNode -> data = data;
            newNode -> next = 0;

            if(head == 0) {
                head = newNode;
            } else {
                node *temp = head;
                while (temp -> next != 0) {
                    temp = temp -> next;
                }
                temp -> next = newNode;
            }
        }
        cout << "\nList awal: ";

        node *temp = head;
        while (temp != 0) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;

        node *current = head;
        node *prev = 0;
        node *next = 0;

        while (current != 0) {
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
        }
        head = prev;

        cout << "Reserved list: ";

        temp = head;
        while (temp != 0) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }

        cout << "\n\Apakah anda ingin menginput angka-angka baru? (y/n)"; 
        cin >> ulang;

        if (ulang == 'y' || ulang == 'Y') {
            continue;
        } else {
            cout << "Program berakhir." << endl;
            cout << "Program ini dibuat oleh: Rolis Liu" << endl;
            cout << "NPM: 2310631170117" << endl;
            break;
        }
    } while (ulang =='y' || 'Y');

    return 0;
}
