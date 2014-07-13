#include <iostream>
#include "LinkedList.h"

using namespace std;

void fillLinkedList (LinkedList &l) {
    for (int k = 0; k < 5; ++k) {
        for (int i = 0; i < 10; ++i) {
            l.addToTail(i);
        }
    }
}

void testAlgs (LinkedList &l, string what) {
    cout << "----------------" << endl;
    cout << what << endl;
    l.print();
    cout << endl;
    cout << "Space cost" << endl;
    l.removeDuplicatesSpaceCost();
    l.print();

    cout << endl;

    cout << "Time cost iterative " << endl;
    l.removeDuplicatesTimeCostIt();
    l.print();

    cout << endl;

    cout << "Time cost recursive" << endl;
    l.removeDuplicatesTimeCostRec();
    l.print();

    cout << endl;

}

int main () {
    LinkedList l1;
    fillLinkedList(l1);
    testAlgs(l1, "Generic case");

    LinkedList l2;
    l2.addToTail(3);
    l2.addToTail(2);
    l2.addToTail(1);
    testAlgs(l2,"Trying without dups");

    LinkedList l3(1);
    testAlgs(l3, "Trying with one element");

    LinkedList l4;
    l4.addToTail(1);
    l4.addToTail(1);
    l4.addToTail(1);
    l4.addToTail(1);
    testAlgs(l4, "Trying with all elements equal");
}
