#include "MyHashNode.h"
#include <cstddef>
#include <vector>

class MyHashTable {
    private:
        std::vector<MyHashNode*> symTable;
        const static int size = 8;
        int hash(char);

    public:
        MyHashTable() : symTable(size, NULL) {};

        void add(char, int);
        void remove(char);
        bool lookUp(char);

        ~MyHashTable();

};
