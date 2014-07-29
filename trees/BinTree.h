#ifndef BINTREE_H
#define BINTREE_H

#include "Tree.h"
#include "BinNode.h"

class BinTree: public Tree {
    protected:
        void insertRec(int,BinNode*);

    public:
        BinTree(void);
        BinTree(int);
        BinTree(Node*);

        void insert(int);
};

#endif
