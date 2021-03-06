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
    pHead = new NodeLinked(val);
}

int LinkedList::getSize() {
    NodeLinked *n = pHead;
    int count = 1;
    while (n->pNext != NULL) {
        n = n->pNext;
        ++count;
    }
    return count;
}

NodeLinked* LinkedList::nthToLast (int n) {
    int size = this->getSize();
    NodeLinked *result = NULL;
    if (size == n - 1) result = pHead;
    else if (size > n) {
        int offset = size - n;
        result = pHead;
        for (int i = 1; i <= offset; ++i) {
            result = result->pNext;
        }
    }
    return result;
}

NodeLinked* LinkedList::nthToLastImproved (int n) {
    if (pHead == NULL or n < 1) return NULL;

    NodeLinked* p1 = pHead;
    NodeLinked* p2 = pHead;

    // Run p2 n positions
    for (int i = 0; i < n-1; ++i) {
        if (p2 == NULL) return NULL; // list size < n
        p2 = p2->pNext;
    }

    while (p2->pNext != NULL) {
        p1 = p1->pNext;
        p2 = p2->pNext;
    }
    return p1;
}

void LinkedList::deleteNodeLinked (NodeLinked *del) {
    if (pHead == NULL)
        return;

    if (pHead->data == del->data and pHead->pNext == del->pNext) {
        pHead = pHead->pNext;
        return;
    }

    NodeLinked *n = pHead;
    while (n->pNext != NULL) {
        if (n->pNext->data == del->data and n->pNext->pNext == del->pNext) {
            n->pNext = n->pNext->pNext;
            return;
        }
        n = n->pNext;
    }
}

void LinkedList::deleteNodeLinked (int val) {
    if (pHead == NULL)
        return;

    if (pHead->data == val) {
        pHead = pHead->pNext;
        return;
    }

    NodeLinked *n = pHead;
    while (n->pNext != NULL) {
        if (n->pNext->data == val) {
            n->pNext = n->pNext->pNext;
            return;
        }
        n = n->pNext;
    }
}

void LinkedList::addToTail (NodeLinked* end) {
    if (pHead == NULL) {
        pHead = end;
        return;
    }
    NodeLinked *n = pHead;
    while (n->pNext != NULL) {
        n = n->pNext;
    }
    n->pNext = end;
}

void LinkedList::addToTail (int val) {
    NodeLinked *end = new NodeLinked(val);
    if (pHead == NULL) {
        pHead = end;
        return;
    }
    NodeLinked *n = pHead;
    while (n->pNext != NULL) {
        n = n->pNext;
    }
    n->pNext = end;
}

void LinkedList::removeDuplicatesSpaceCost () {
    if (pHead == NULL or pHead->pNext == NULL) return;

    map <int, bool> appears;
    NodeLinked *n = pHead;
    appears[n->data] = true;

    NodeLinked *previous;
    while (n->pNext->pNext != NULL) {
        if (appears.find(n->pNext->data) != appears.end()) {
            // Found
            this->deleteNodeLinked(n->pNext);
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

void LinkedList::removeDuplicatesAux (NodeLinked *toSearch) {
    if (toSearch == NULL) return;

    NodeLinked *n = pHead;
    NodeLinked *previous = new NodeLinked();
    while (*n != toSearch) {
        n = n->pNext;
        if (n->pNext == NULL) return;
    }

    NodeLinked *elem = n;
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

    NodeLinked *n = pHead;
    NodeLinked *aux;
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
    NodeLinked *p = pHead;
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
