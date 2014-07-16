#include <iostream>
#include "setOfStacks.h"

using namespace std;

SetOfStacks::SetOfStacks (int size) {
    current = NULL;
    maxSize = size;
}

SetOfStacks::SetOfStacks (int size, int val) {
    maxSize = size;
    current = new Stack(val);
}

void SetOfStacks::push (int val) {
    if (current == NULL) {
        current = new Stack(val);
    }
    else if (current->getSize() < maxSize) {
        current->push(val);
    }
    else {
        Stack *newCurrent = new Stack(val);
        Stack *oldStack   = current;
        newCurrent->setNextStack(oldStack);
        current = newCurrent;
    }
}

int SetOfStacks::pop () {
    if (current == NULL) return -1;

    int result = current->pop();
    if (current->getSize() == 0) {
        Stack *newCurrent, *freeStack;
        freeStack  = current;
        current    = current->getNextStack();
        delete freeStack;
    }
    return result;
}

int SetOfStacks::popAt (int index) {
    if (current == NULL) return -1;
    if (index   == 0)    return current->pop();

    Stack *pStack, *pPrevious;
    pStack = current->getNextStack();
    for (int i = 1; i < index; ++i) {
        pPrevious = pStack;
        pStack = pStack->getNextStack();
    }

    int result = pStack->pop();
    if (pStack->getSize() == 0) {
        Stack *pOldNextStack = pStack->getNextStack();
        pPrevious->setNextStack(pOldNextStack);
        delete pStack;
        pStack = NULL;
    }

    return result;
}

void SetOfStacks::print () {
    if (current == NULL) {
        cout << "Empty set of stacks" << endl;
        return;
    }

    Stack *pStack = current;
    while (pStack != NULL) {
        cout << endl;
        Node *n = pStack->getTop();
        cout << "Size " << pStack->getSize() << endl;
        for (int i = 0; i < pStack->getSize(); ++i) {
            cout << n->getData() << ' ';
            n = n->getNextNode();
        }
        cout << endl;
        pStack = pStack->getNextStack();
    }
}
