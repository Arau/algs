#include "Node.h"

class Queue {
    private:
        Node *front;
        Node *back;

    public:
        Queue(void);
        Queue(int);

        void enqueue(int);
        Node* dequeue(void);

        void print(void);
};
