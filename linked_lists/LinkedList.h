#include "Node.h"

class LinkedList {
    private:
        Node *pHead;

    public:
        LinkedList(void);
        LinkedList(int);

        void deleteNode(Node*);
        void deleteNode(int);
        void addToTail(Node*);
        void addToTail(int);
        void print(void);
};
