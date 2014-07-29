#include <iostream>
#include "BinTree.h"

// Assume that 2 values are in the tree
BinNode* firstCommonAncestor (BinTree *t, int a, int b) {
    BinNode *root = (BinNode*) t->getRoot();
    int val = root->getData();
    if ( val == a or val == b ) {
        return root;
    } else {
        BinTree *subTreeLeft  = new BinTree ( root->getLeftChild() );
        BinTree *subTreeRight = new BinTree ( root->getRightChild() );
        bool lA, rA, lB, rB;

        lA = subTreeLeft->find(a);
        rB = subTreeRight->find(b);
        if (lA and rB) { return root; }

        lB = subTreeLeft->find(b);
        rA = subTreeRight->find(a);
        if (lB and rA) { return root; }

        if (lA and lB) {
            return firstCommonAncestor(subTreeLeft, a, b);
        }
        else if (rA and rB) {
            return firstCommonAncestor(subTreeRight, a, b);
        }
    }
}

void testAncestor (BinTree &t, int a, int b) {
    BinNode *ancestor = firstCommonAncestor(&t, a, b);
    cout << "Ancestor between " << a << " and " << b << ": " << ancestor->getData() << endl;
}

int main () {
    BinTree t1;
    t1.insert(1);
    BinNode *r = (BinNode*) t1.getRoot();
    r->addLeftChild(2);
    r->addRightChild(3);
    r->getLeftChild()->addLeftChild(4);
    r->getLeftChild()->addRightChild(5);
    r->getRightChild()->addLeftChild(6);
    r->getRightChild()->addRightChild(7);


    testAncestor(t1, 1, 3);
    testAncestor(t1, 1, 2);
    testAncestor(t1, 4, 6);
    testAncestor(t1, 4, 5);
    testAncestor(t1, 2, 3);
    testAncestor(t1, 6, 7);

}
