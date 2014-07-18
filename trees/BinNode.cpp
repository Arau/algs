#include <iostream>
#include <vector>
#include "BinNode.h"

const vector<Node*> BinNode::initChilds () {
    const vector<Node*> childs (2, NULL);
    return childs;
}

void BinNode::addLeftChild (int val) {
    Node* l = new BinNode(val);
    this->children[0] = l;
}

void BinNode::addRightChild (int val) {
    Node* r = new BinNode(val);
    this->children[1] = r;
}
