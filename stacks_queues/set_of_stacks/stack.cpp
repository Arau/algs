#include <cstddef>
#include <iostream>
#include "stack.h"

using namespace std;

Stack::Stack () {
    top        = NULL;
    pNextStack = NULL;
    size       = 0;
}

Stack::Stack (int val) {
    top        = new Node(val);
    pNextStack = NULL;
    size       = 1;
}

Stack::Stack (int val, Stack *pStack) {
    top        = new Node(val);
    pNextStack = pStack;
    size       = 1;
}

int Stack::pop () {
    if (top == NULL) return -1;

    Node *t = top;
    top = t->pNext;
    --size;
    return t->data;
}

void Stack::push (int val) {
    Node *t = new Node(val);
    if (top == NULL) {
        top  = t;
        size = 1;
    } else {
        t->pNext = top;
        top = t;
        ++size;
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
