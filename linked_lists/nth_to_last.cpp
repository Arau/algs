#include <iostream>
#include "LinkedList.h"

using namespace std;

void test_case (LinkedList &l, int nthToLast, int alg) {
    cout << "Checking " << nthToLast << endl;
    l.print();
    Node *res;
    if (alg == 0)      res = l.nthToLast(nthToLast);
    else if (alg == 1) res = l.nthToLastImproved(nthToLast);

    if (res == NULL) cout << "NULL" << endl;
    else cout << "Nth to last: " << nthToLast << " -> data: " << res->getData() << endl;
    cout << endl;
}

int main () {
    LinkedList l;
    for (int i = 9; i >= 0; --i) l.addToTail(i);

    cout << "Basic alg" << endl;
    test_case (l, 0, 0);
    test_case (l, 1, 0);
    test_case (l, 5, 0);
    test_case (l, 9, 0);
    test_case (l, 10, 0);
    test_case (l, 22, 0);


    cout << "--------------------" << endl;
    cout << "Improved alg" << endl;
    test_case (l, 0, 1);
    test_case (l, 1, 1);
    test_case (l, 5, 1);
    test_case (l, 9, 1);
    test_case (l, 10, 1);
    test_case (l, 22, 1);

}
