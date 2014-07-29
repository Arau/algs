#include <iostream>
#include <vector>
#include "BinSearchTree.h"
#include "LinkedList.h"

using namespace std;

void convert_tree (BinNode* parent, vector<LinkedList*> &v, int deep) {
    if (not parent) return;

    LinkedList *l;
    if (v.size() < deep + 1) {
        l = new LinkedList( parent->getData() );
        v.push_back(l);
    } else {
        l = v[deep];
        l->addToTail( parent->getData() );
    }

    convert_tree(parent->getLeftChild() , v, deep + 1);
    convert_tree(parent->getRightChild(), v, deep + 1);
}

vector<LinkedList*> lists_from_tree (BinSearchTree &t) {
    Node *root = t.getRoot();
    vector<LinkedList*> result;
    convert_tree((BinNode*) root, result, 0);
    return result;
}

void insertBalancedBinTree(const vector<int>& v, BinSearchTree& t, int l, int r) {
    if (l < r) {
        int mid = l + ( (r - l)/2 );
        t.insert( v[mid] );
        insertBalancedBinTree(v, t, l, mid - 1);
        insertBalancedBinTree(v, t, mid + 1, r);
    }
}

int main () {
    int size = 20;
    vector<int> v(size);
    for (int i = 0; i < size; ++i) { v[i] = i+i*2; }
    BinSearchTree t;
    insertBalancedBinTree(v, t, 0, size);

    vector<LinkedList*> lists = lists_from_tree(t);
    for (int i = 0; i < lists.size(); ++i) {
        lists[i]->print();
        cout << endl;
    }
}
