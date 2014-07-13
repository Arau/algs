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
        bool operator!= (Node* n) {
            return (this->data != n->data) and (this->pNext != n->pNext);
        }
        bool operator== (Node* n) {
            return (this->data == n->data) and (this->pNext == n->pNext);
        }
};
