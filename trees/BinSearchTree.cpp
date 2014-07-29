#include <iostream>
#include <vector>
#include "BinSearchTree.h"

using namespace std;

BinSearchTree::BinSearchTree () { }

BinSearchTree::BinSearchTree (int val) {
    root = new BinNode(val);
}

void BinSearchTree::insertRec (int val, BinNode *parent) {
    Node* l = (BinNode*) parent->getLeftChild();
    Node* r = (BinNode*) parent->getRightChild();
    if (val <= parent->getData()) {
        if (!l) {
            cout << "Inserting " << val << " -> left -> " << parent->getData() << endl;
            parent->addLeftChild(val);
        } else {
            insertRec(val, parent->getLeftChild());
        }
    } else {
        if (!r) {
            cout << "Inserting " << val << " -> right -> " << parent->getData() << endl;
            parent->addRightChild(val);
        } else {
            insertRec(val, parent->getRightChild());
        }
    }
}


void BinSearchTree::insert (int val) {
    if (root->getData() == -1) root = new BinNode(val);
    else
        this->insertRec(val, (BinNode*) root);
}
