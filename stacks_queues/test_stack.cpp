#include <iostream>
#include "Stack.h"

using namespace std;

int main () {
    Stack s(1);
    s.push(2);
    s.push(3);
    s.print();

    cout << endl;

    cout << "Min " << s.getMin() << endl;

    Node *n = s.pop();
    cout << "Pop: " << n->getData() << endl;
    s.print();

    n = s.pop();
    cout << "Pop: " << n->getData() << endl;
    s.print();

    n = s.pop();
    cout << "Pop: " << n->getData() << endl;
    s.print();


    s.push(3);
    s.push(1);
    s.push(2);
    s.print();
    cout << "Min " << s.getMin() << endl;
}


