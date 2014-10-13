#include "MyHashTable.h"




int MyHashTable::hash (char c) {
    int m = 30; // Constant token
    int rand = 1; // Supose that it is a rand num between 0-1
    return (rand*m) % this->size;
}

bool MyHashTable::lookUp (char c) {
    int h = this->hash(c);

    if (this->symTable[h] != NULL) {
        return true;
    }
    return false;
}
