#include "Tree.h"
#include "BinNode.h"

class BinTree: public Tree {
    protected:
        void insertRec(int,BinNode*);

    public:
        BinTree(void);
        BinTree(int val);

        void insert(int);
};
