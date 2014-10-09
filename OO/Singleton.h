#include <cstddef>

class Singleton {
    static Singleton* pInstance;
    int a;

    protected:
        Singleton(int a) : a(a) {};

    public:
        static Singleton* getInstance(int);
        int getA(void) { return a; }

};
