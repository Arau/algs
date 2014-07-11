#include <cstddef>

class Node {
    friend class LinkedList;

    private:
        int data;
        Node *pNext;

    public:
        Node(void)                : pNext(NULL) { }
        Node(int val)             : data(val), pNext(NULL) { }
        Node(int val, Node* next) : data(val), pNext(next) { }
};
