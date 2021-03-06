#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree {
    private:

        bool findRec(int,Node*);
        void deleteNodeRec(int,Node*);
        void promoteChild(void);
        void takeChildren(Node*,Node*);
        void printRec(Node*);
        int isBalancedRec(Node*);

    protected:
        Node* root;

    public:
        Tree(void)    : root(NULL)  {}
        Tree(Node *r) : root(r)     {}
        Tree(int val) { root = new Node(val); }

        Node* getRoot(void) { return root; }
        bool find(int);
        bool isBalanced();
        void deleteNode(int);
        void print(void);
};

#endif
