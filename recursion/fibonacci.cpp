#include <iostream>
#include <vector>

using namespace std;

int fib_rec (int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return fib_rec(n-1) + fib_rec(n-2);
}

int fib_rec2 (int n) {
    return (n <= 1) ? n : fib_rec2(n-1) + fib_rec2(n-2);
}

int main () {
    int n;
    while (cin >> n) {
        int fib = fib_rec (n);
        cout << "Fib rec " << fib << ' ' << endl;
    }
}
