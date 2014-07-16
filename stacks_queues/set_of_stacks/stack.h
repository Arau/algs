#include "Node.h"

class Stack {
    private:
        Node  *top;
        Stack *pNextStack;
        int size;

    public:
        // Constructors
        Stack(void);
        Stack(int);
        Stack(int,Stack*);

        // Getters and Setters
        Node*   getTop(void)        { return top;  }
        Stack*  getNextStack(void)  { return pNextStack; }
        int     getSize(void)       { return size; }

        void  setNextStack(Stack* p) { pNextStack = p; }

        // Methods
        int  pop(void);
        void push(int);

        // Output
        void print(void);
};
