#include <iostream>
#include "LinkedList.h"

using namespace std;

int main () {
    LinkedList list1;
    cout << "Created list empty" << endl;

    cout << "list1:" << endl;
    list1.print();

    LinkedList list11(1);
    cout << endl << "List created with one node" << endl;

    cout << "list11:" << endl;
    list11.print();

    LinkedList list2;
    cout << endl << "Creating nodes and adding to tail, to list2:" << endl;
    for (int i = 0; i < 10; ++i) {
        Node *n = new Node(i);
        list2.addToTail(n);
    }
    list2.print();

    cout << "Add nodes to list2 passing values:" << endl;
    for (int i = 10; i < 20; ++i) {
        list2.addToTail(i);
    }
    list2.print();


    Node *toDel = new Node(0);
    list2.deleteNode(toDel);
    cout << endl << "Delete head of linked list" << endl;
    list2.print();

    Node *toDel2 = new Node(10);
    list2.deleteNode(toDel2);
    cout << endl << "Delete node 10" << endl;
    list2.print();

    list2.deleteNode(1);
    cout << endl << "Delete node 1, it should was the head" << endl;
    list2.print();

    list2.deleteNode(12);
    cout << endl << "Delete node 12" << endl;
    list2.print();
}
