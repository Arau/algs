#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BinTree.h"

int main () {
    BinTree t1;
    t1.insert(1);
    t1.insert(5);
    t1.insert(9);
    t1.insert(0);
    t1.insert(25);
    t1.insert(4);
    t1.insert(1);
    t1.insert(6);
    t1.insert(10);
    t1.insert(2);
    t1.insert(29);
    t1.insert(3);

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        t1.insert(num);
    }

    cout << endl << endl;

    BinTree t2;
    t2.insert(1);
    t2.insert(2);
    t2.insert(3);
    t2.insert(4);
    t2.insert(5);
    t2.insert(6);

    if (t2.isBalanced())  cout << "Balanced" << endl;
    else                  cout << "Not Balanced" << endl;
}
