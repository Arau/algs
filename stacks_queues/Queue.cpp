#include <cstddef>
#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue () {
    front = back = NULL;
}

Queue::Queue (int val) {
    front = back = new Node(val);
}

Node* Queue::dequeue () {
    if (front == NULL) return NULL;

    Node *t = front;
    front = t->pNext;
    return t;
}

void Queue::enqueue (int val) {
    Node *t = new Node(val);
    if (front == NULL) front = back = t;
    else {
        Node *oldBack = back;
        Node *newBack = t;
        oldBack->pNext = newBack;
        back = newBack;
    }
}

void Queue::print () {
    if (front == NULL) {
        cout << "Empty queue" << endl;
        return;
    }
    Node *n = front;
    while (n != NULL) {
        cout << n->data << ' ' << endl;
        n = n->pNext;
    }
}
