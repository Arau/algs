#include <iostream>
#include "Queue.h"

using namespace std;

int main () {
    Queue q(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();

    cout << endl;

    Node *n = q.dequeue();
    cout << "Dequeue: " << n->getData() << endl;
    q.print();

    n = q.dequeue();
    cout << "Dequeue: " << n->getData() << endl;
    q.print();

    n = q.dequeue();
    cout << "Dequeue: " << n->getData() << endl;
    q.print();
}


