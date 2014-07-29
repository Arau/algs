#ifndef BINNODE_H
#define BINNODE_H

#include "Node.h"

using namespace std;

class BinNode : public Node {
    private:
        const vector<Node*> initChilds(void);

    public:
        BinNode(int val) : Node( val, initChilds() ) {}

        BinNode* getLeftChild(void)  { return (BinNode*) children[0]; }
        BinNode* getRightChild(void) { return (BinNode*) children[1]; }

        void addLeftChild(int);
        void addRightChild(int);
};

#endif
