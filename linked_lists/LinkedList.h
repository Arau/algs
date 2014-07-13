#include "Node.h"

class LinkedList {
    private:
        Node *pHead;
        void removeDuplicatesAux(Node*);

    public:
        LinkedList(void);
        LinkedList(int);

        void deleteNode(Node*);
        void deleteNode(int);
        void addToTail(Node*);
        void addToTail(int);
        void removeDuplicatesSpaceCost(void);
        void removeDuplicatesTimeCostRec(void);
        void removeDuplicatesTimeCostIt(void);
        void print(void);
};
