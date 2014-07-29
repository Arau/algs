#include "NodeLinked.h"

class LinkedList {
    private:
        NodeLinked *pHead;
        void removeDuplicatesAux(NodeLinked*);
        int  getSize();

    public:
        LinkedList(void);
        LinkedList(int);

        NodeLinked* nthToLast(int);
        NodeLinked* nthToLastImproved(int);
        void deleteNodeLinked(NodeLinked*);
        void deleteNodeLinked(int);
        void addToTail(NodeLinked*);
        void addToTail(int);
        void removeDuplicatesSpaceCost(void);
        void removeDuplicatesTimeCostRec(void);
        void removeDuplicatesTimeCostIt(void);
        void print(void);
};
