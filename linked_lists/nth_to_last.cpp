#include <iostream>
#include "LinkedList.h"

using namespace std;

void test_case (LinkedList &l, int nthToLast) {
    cout << "Checking " << nthToLast << endl;
    l.print();
    Node *res = l.nthToLast(nthToLast);
    if (res == NULL) cout << "NULL" << endl;
    else cout << "End to last: " << nthToLast << " -> " << res->getData() << endl;
    cout << endl;
}

int main () {
    LinkedList l;
    for (int i = 9; i >= 0; --i) l.addToTail(i);

    test_case (l, 0);
    test_case (l, 1);
    test_case (l, 5);
    test_case (l, 9);
    test_case (l, 10);
    test_case (l, 22);
}
