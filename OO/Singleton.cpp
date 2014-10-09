#include "Singleton.h"

Singleton *Singleton::pInstance = 0;

Singleton* Singleton::getInstance(int a) {
    if (pInstance == NULL) {
        pInstance = new Singleton(a);
    }
    return pInstance;
}
