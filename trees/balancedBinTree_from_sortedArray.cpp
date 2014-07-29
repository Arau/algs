#include <iostream>
#include <vector>
#include "BinSearchTree.h"

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
}
