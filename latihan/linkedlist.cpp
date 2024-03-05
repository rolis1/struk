#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main () {
    node* head = new node();
    head->data = 1;
    head->next = NULL;

    node* second = new node();
    second->data = 2;
    second->next = NULL;

    head->next = second;

    node* third = new node();
    third->data = 3;
    third->next = NULL;

    second->next = third;

    node* node = head;
    while(node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }

    return 0;
}