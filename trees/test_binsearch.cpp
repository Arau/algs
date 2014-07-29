#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "BinSearchTree.h"

int main () {
    BinSearchTree t1(50);

    srand(time(NULL));
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100;
        t1.insert(num);
    }

    t1.insert(1);
    t1.insert(2);
    t1.insert(61);
    t1.insert(70);
}
