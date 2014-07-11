#include <iostream>
#include <cstddef>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList () {
    pHead = NULL;
}

LinkedList::LinkedList (int val) {
    pHead = new Node(val);
}

void LinkedList::deleteNode(Node *del) {
    if (pHead == NULL)
        return;

    if (pHead->data == del->data) {
        pHead = pHead->pNext;
        return;
    }

    Node *n = pHead;
    while (n->pNext != NULL) {
        if (n->pNext->data == del->data) {
            n->pNext = n->pNext->pNext;
            return;
        }
        n = n->pNext;
    }
}

void LinkedList::deleteNode(int val) {
    if (pHead == NULL)
        return;

    if (pHead->data == val) {
        pHead = pHead->pNext;
        return;
    }

    Node *n = pHead;
    while (n->pNext != NULL) {
        if (n->pNext->data == val) {
            n->pNext = n->pNext->pNext;
            return;
        }
        n = n->pNext;
    }
}

void LinkedList::addToTail (Node* end) {
    if (pHead == NULL) {
        pHead = end;
        return;
    }
    Node *n = pHead;
    while (n->pNext != NULL) {
        n = n->pNext;
    }
    n->pNext = end;
}

void LinkedList::addToTail (int val) {
    Node *end = new Node(val);
    if (pHead == NULL) {
        pHead = end;
    }
    Node *n = pHead;
    while (n->pNext != NULL) {
        n = n->pNext;
    }
    n->pNext = end;
}

void LinkedList::print () {
    Node *p = pHead;
    if (pHead == NULL) {
        cout << "List empty" << endl;
        return;
    }

    while (p != NULL) {
        cout << p->data << ' ';
        p = p->pNext;
    }
    cout << endl;
}
