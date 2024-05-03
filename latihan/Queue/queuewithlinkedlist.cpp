#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
struct Queue
{
    Node *front;
    Node *rear;
};
// inisialisasi queue
void initQueue(Queue* q)
{
    q-> front = q -> rear = NULL;
}
// cek apakah queue kosong
bool isEmpty(Queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

// enqueue data
void enqueue(Queue* q, int data)
{
    Node* newNode = new Node;
    newNode -> data = data;
    newNode ->  next = NULL;
    if (isEmpty(q))
    {
        q -> front = q -> rear = newNode;
    }
    else
    {
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
}