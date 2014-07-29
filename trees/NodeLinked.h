#include <cstddef>

class NodeLinked {
    friend class LinkedList;

    private:
        int data;
        NodeLinked *pNext;

    public:
        // Constructor
        NodeLinked(void)                : pNext(NULL) { }
        NodeLinked(int val)             : data(val), pNext(NULL) { }
        NodeLinked(int val, NodeLinked* next) : data(val), pNext(next) { }

        // Operators
        bool operator!= (NodeLinked* n) {
            return (this->data != n->data) and (this->pNext != n->pNext);
        }
        bool operator== (NodeLinked* n) {
            return (this->data == n->data) and (this->pNext == n->pNext);
        }

        // Getters
        int getData(void) { return data; }
};
