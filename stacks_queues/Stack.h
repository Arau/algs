#include "Node.h"

class Stack {
    private:
        Node *top;
        Node *min;
        void setNewMin(void);

    public:
        Stack(void);
        Stack(int);

        int getMin(void) { return min->data; }

        Node* pop(void);
        void push(int);

        void print(void);
};
