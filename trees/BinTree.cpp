#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "BinTree.h"

using namespace std;

BinTree::BinTree () {
    srand(time(NULL));
    root = new BinNode(-1);
}

BinTree::BinTree (int val) {
    srand(time(NULL));
    root = new BinNode(val);
}

void BinTree::insertRec (int val, BinNode *parent) {
    Node *l, *r, *n;
    n = new BinNode(val);
    l = parent->getLeftChild();
    r = parent->getRightChild();
    if ( (!l and !r) or (!l and r) )  {
        parent->addLeftChild(val);
        cout << "Inserting " << val << " -> left  -> " << parent->getData() << endl;
    }
    else if ( l and !r ) {
        parent->addRightChild(val);
        cout << "Inserting " << val << " -> right -> " << parent->getData() << endl;
    }
    else {
        int decission = rand() % 2;
        BinNode *next;
        if (!decission) next = parent->getLeftChild();
        else            next = parent->getRightChild();

        this->insertRec(val, next);
    }
}


void BinTree::insert (int val) {
    if (root->getData() == -1) {
        cout << "Create root " << val << endl;
        root->setData(val);
        return;
    }
    if ( not find(val) ) {
        this->insertRec(val, (BinNode*) root);
    }
}
