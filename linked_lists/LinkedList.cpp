#include <iostream>
#include <cstddef>
#include <map>
#include <vector>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList () {
    pHead = NULL;
}

LinkedList::LinkedList (int val) {
    pHead = new Node(val);
}

int LinkedList::getSize() {
    Node *n = pHead;
    int count = 1;
    while (n->pNext != NULL) {
        n = n->pNext;
        ++count;
    }
    return count;
}

Node* LinkedList::nthToLast(int n) {
    int size = this->getSize();
    Node *result = NULL;
    if (size == n - 1) result = pHead;
    else if (size > n) {
        int offset = size - n - 1;
        result = pHead;
        for (int i = 1; i <= offset; ++i) {
            result = result->pNext;
        }
    }
    return result;
}

void LinkedList::deleteNode (Node *del) {
    if (pHead == NULL)
        return;

    if (pHead->data == del->data and pHead->pNext == del->pNext) {
        pHead = pHead->pNext;
        return;
    }

    Node *n = pHead;
    while (n->pNext != NULL) {
        if (n->pNext->data == del->data and n->pNext->pNext == del->pNext) {
            n->pNext = n->pNext->pNext;
            return;
        }
        n = n->pNext;
    }
}

void LinkedList::deleteNode (int val) {
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
        return;
    }
    Node *n = pHead;
    while (n->pNext != NULL) {
        n = n->pNext;
    }
    n->pNext = end;
}

void LinkedList::removeDuplicatesSpaceCost () {
    if (pHead == NULL or pHead->pNext == NULL) return;

    map <int, bool> appears;
    Node *n = pHead;
    appears[n->data] = true;

    Node *previous;
    while (n->pNext->pNext != NULL) {
        if (appears.find(n->pNext->data) != appears.end()) {
            // Found
            this->deleteNode(n->pNext);
        } else {
            appears[n->pNext->data] = true;
            previous = n;
            n = n->pNext;
        }
    }

    // Last node
    if (appears.find(n->pNext->data) != appears.end()) {
        //Found
        n->pNext = NULL;
    }
}

void LinkedList::removeDuplicatesAux (Node *toSearch) {
    if (toSearch == NULL) return;

    Node *n = pHead;
    Node *previous = new Node();
    while (*n != toSearch) {
        n = n->pNext;
        if (n->pNext == NULL) return;
    }

    Node *elem = n;
    while (n->pNext->pNext != NULL) {
        if (n->pNext->data == elem->data) {
            n->pNext = n->pNext->pNext;
        } else {
            n = n->pNext;
        }
    }

    // Last item
    if (n->pNext->data == elem->data) {
        n->pNext = NULL;
    }

    this->removeDuplicatesAux(toSearch->pNext);
}

void LinkedList::removeDuplicatesTimeCostRec () {
    if (pHead == NULL or pHead->pNext == NULL) return;
    removeDuplicatesAux(pHead);
}

void LinkedList::removeDuplicatesTimeCostIt () {
    if (pHead == NULL or pHead->pNext == NULL) return;

    Node *n = pHead;
    Node *aux;
    while (n != NULL) {
        aux = n;
        if (aux->pNext != NULL) {
            while (aux->pNext->pNext != NULL) {
                if (aux->pNext->data == n->data) {
                    aux->pNext = aux->pNext->pNext;
                } else {
                    aux = aux->pNext;
                }
            }
            // Last item
            if (aux->pNext->data == n->data) {
                aux->pNext = NULL;
            }
        }
        n = n->pNext;
    }
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
