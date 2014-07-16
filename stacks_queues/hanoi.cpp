#include <iostream>
#include "Stack.h"

using namespace std;

void mvItem (Stack &s1, Stack &s2) {
    Node *n = s1.pop();
    if (n != NULL)
        s2.push( n->getData() );
}

void hanoi (int size, Stack &orig, Stack &dest, Stack &aux) {
    if (size == 0) {
        mvItem(orig, dest);
    } else {
        hanoi(size - 1, orig, aux, dest);
        mvItem(orig, dest);
        hanoi(size - 1, aux, dest, orig);
    }
}

int main () {
    Stack s1, s2, s3;
    int sizeOfTower = 10;
    for (int i = 0; i < sizeOfTower; ++i) {
        s1.push(i);
    }
    cout << "s1" << endl;
    s1.print();

    hanoi(sizeOfTower, s1, s2, s3);

    cout << "s1" << endl;
    s1.print();
    cout << endl;
    cout << "s2" << endl;
    s2.print();
    cout << endl;
    cout << "s3" << endl;
    s3.print();
}
