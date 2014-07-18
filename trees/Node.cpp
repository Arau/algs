#include "Node.h"
#include <iostream>

using namespace std;

Node::Node () {
    data = -1;
    children = vector<Node*>();
}

Node::Node (int val) {
    data = val;
    children = vector<Node*>();
}

Node::Node (const vector<Node*>& children) {
    data = -1;
    this->children = children;
}

Node::Node (int val, const vector<Node*>& children) {
    data = val;
    this->children = children;
}

void Node::addChild(Node *n, int pos) {
    if (children.size() == 0) {
        const vector<Node*> v(pos+1, NULL);
        children = v;
        children[pos] = n;
    }
}

bool Node::isLeave () {
    bool res = false;
    int size = children.size();
    if (size == 0) res = true;
    else {
        bool found = false;
        for (int i = 0; i < size; ++i) {
            if (children[i] != NULL) found = true;
        }
        if (!found) res = true;
    }
    return res;
}
