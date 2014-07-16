#include <cstddef>

class Node {
    friend class Stack;

    private:
        int data;
        Node *pNext;

    public:
        // Constructor
        Node(void)                : pNext(NULL) { }
        Node(int val)             : data(val), pNext(NULL) { }
        Node(int val, Node* next) : data(val), pNext(next) { }

        // Operators
        bool operator!= (Node* n) {
            return (this->data != n->data) and (this->pNext != n->pNext);
        }
        bool operator== (Node* n) {
            return (this->data == n->data) and (this->pNext == n->pNext);
        }

        // Getters
        int   getData(void)     { return data; }
        Node* getNextNode(void) { return pNext; }
};
