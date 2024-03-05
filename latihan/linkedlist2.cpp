#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

struct dataKtp {
    char nama[50];
    char alamat[50];
    char golDarah[2];

    dataKtp *nextNode, *prevNode;
};


dataKtp *first=NULL, *last=NULL, *loopHelper, *newNode;

void inputDataDepan() {
    newNode = new dataKtp;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    cout << "Nama : ";
    cin >> newNode->nama;
    cout << newNode->alamat;
    cout << "Golongan darah : ";
    cin >> newNode->golDarah;

    if(first == NULL) {
        first = last = newNode;
    } else {
        newNode->nextNode = first;
        first->prevNode = newNode;
        first = newNode;
    }

    system("cls");

}


void inputDataDepan() {
    newNode = new dataKtp;
    newNode->nextNode = NULL;
    newNode->prevNode = NULL;
    cout << "Nama : ";
    cin >> newNode->nama;
    cout << newNode->alamat;
    cout << "Golongan darah : ";
    cin >> newNode->golDarah;

    if(first == NULL) {
        first = last = newNode;
    } else {
        last->nextNode = newNode;
        newNode->prevNode = last;
        last = newNode;
    }

    system("cls");

}

void outputData() {
    loopHelper = first;
}



