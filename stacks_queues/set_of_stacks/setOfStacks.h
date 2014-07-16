#include "stack.h"

class SetOfStacks {
    private:
        Stack *current;
        int maxSize;

    public:
        SetOfStacks(int);
        SetOfStacks(int,int);

        int  pop(void);
        int  popAt(int);
        void push(int);
        void print(void);
};
