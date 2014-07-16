#include <iostream>
#include "setOfStacks.h"


using namespace std;

int main () {
    int sizeOfStacks = 10;
    SetOfStacks ss(sizeOfStacks);

    cout << endl << "------------ Push ---------" << endl;
    for (int i = 0; i < 10; ++i) {
        ss.push(i);
    }

    for (int i = 10; i < 44; ++i) {
        ss.push(i);
    }
    ss.print();

    cout << endl << "---------- PopAt ---------" << endl;
    cout << "Pop at 2 " << ss.popAt(2) << endl;
    ss.print();

    cout << endl << "------------ Pop ---------" << endl;
    cout << "Elem " << ss.pop() << endl;
    ss.print();

    cout << endl << "Pop more elems" << endl;
    for (int i = 0; i < (sizeOfStacks + 5); ++i) {
        cout << "Elem " << ss.pop() << endl;
    }
    ss.print();


    cout << endl << "---------- PopAt ---------" << endl;
    cout << "Pop at 1 " << ss.popAt(1) << endl;
    ss.print();
    cout << "Pop at 0 " << ss.popAt(0) << endl;
    ss.print();
}


