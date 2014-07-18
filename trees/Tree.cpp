#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Tree.h"

using namespace std;

bool Tree::findRec (int val, Node *n) {
    if (n == NULL)      return false;
    if (n->data == val) return true;

    Node *son;
    for (int i = 0; i < n->children.size(); ++i) {
        son = n->children[i]; // Here son could be NULL, CAREFULL
        if ( this->findRec(val, son) == true )
            return true;
    }
    return false;
}

bool Tree::find (int val) {
    if (root == NULL) return false;
    this->findRec(val, root);
}

int Tree::isBalancedRec (Node *parent) {
    if ( parent->isLeave() ) return 1;

    // Base case
    Node *son;
    vector <int> dist;
    int d;
    for (int i = 0; i < parent->children.size(); ++i) {
        son = parent->children[i];
        if (son) {
            d = this->isBalancedRec(son);
            dist.push_back(d);
        }
    }
    int first = dist[0];
    for (int i = 0; i < dist.size(); ++i) {
        if (dist[i] != first or dist[i] == -1)
            return -1;
    }

    return first + 1;
}


bool Tree::isBalanced () {
    bool res = false;
    if ( root->isLeave() ) res = true;
    else {
        int r = this->isBalancedRec(root);
        res = (r == -1)? false : true;
    }
    return res;
}


// n1 takes n2's children
void Tree::takeChildren (Node *n1, Node *n2) {
    for (int i = 0; i < n2->children.size(); ++i) {
        n1->children.push_back( n2->children[i] );
        n2->children[i] = NULL;
    }
}

void Tree::deleteNodeRec (int val, Node *n) {
    if ( n->isLeave() ) return;

    for (int i = 0; i < n->children.size(); ++i) {
        Node *parent = n;
        Node *son    = parent->children[i];
        if (son->data == val) {
            if ( son->isLeave() ) {
                parent->children[i] = NULL;
            } else {
                takeChildren(parent, son);
            }
            delete son;
        } else {
            this->deleteNodeRec(val, son);
        }
    }
}

void Tree::promoteChild () {
    Node *n       = root;
    Node *newRoot = NULL;
    int i = 0;
    while (i < n->children.size() and newRoot == NULL) {
        if (n->children[i] != NULL) newRoot = n->children[i];
        ++i;
    }

    Node *oldRoot = root;
    takeChildren (newRoot, oldRoot);
    root = newRoot;
    delete oldRoot;
}

void Tree::deleteNode (int val) {
    if (root->data == val) {
        if ( root->isLeave() ) {
            delete root;
            root = NULL;
        } else
            promoteChild();
    }

    this->deleteNodeRec(val, root);
}

void Tree::printRec (Node *n) {
    if (n == NULL) return;

    cout << n->data << endl;
    if ( not n->isLeave() ) {
        for (int i = 0; i < n->children.size(); ++i) {
            this->printRec(n->children[i]);
        }
    }
}

void Tree::print () {
    if (root == NULL) cout << "Empty" << endl;
    else
        this->printRec(root);
}
