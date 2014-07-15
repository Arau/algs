#include <cstddef>
#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack () {
    top = min = NULL;
}

Stack::Stack (int val) {
    top = min = new Node(val);
}

void Stack::setNewMin () {
    Node* t = top;
    min = t;
    while (t != NULL) {
        if (t->data <= min->data) min = t;
        t = t->pNext;
    }
}

Node* Stack::pop () {
    if (top == NULL) return NULL;

    Node *t = top;
    top = t->pNext;
    if (min == t) this->setNewMin();
    return t;
}

void Stack::push (int val) {
    Node *t = new Node(val);
    if (top == NULL) top = min = t;
    else {
        t->pNext = top;
        top = t;
        if (val < min->data) min = top;
    }
}

void Stack::print () {
    if (top == NULL) {
        cout << "Empty stack" << endl;
        return;
    }
    Node *n = top;
    while (n != NULL) {
        cout << n->data << ' ' << endl;
        n = n->pNext;
    }
}
