#include <iostream>

#include "Singleton.h"

using namespace std;

int main () {
    Singleton *s = Singleton::getInstance(1);
    cout << s->getA() << endl;

    Singleton *s2 = Singleton::getInstance(2);
    cout << s2->getA() << endl;
}
