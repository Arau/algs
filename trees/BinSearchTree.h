#include "BinTree.h"
//#include "BinNode.h"

class BinSearchTree: public BinTree {
    protected:
        void insertRec(int,BinNode*);

    public:
        BinSearchTree(void);
        BinSearchTree(int);

        void insert(int);
};
