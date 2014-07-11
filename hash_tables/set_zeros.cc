#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int>  Line;
typedef vector<Line> Matrix;

struct Pair {
    int x, y;
};

void fillMatrix (Matrix &m) {
    int size = m[0].size();
    int counter = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            m[i][j] = 1;
        }
    }
}

void printMatrix (Matrix &m) {
    int size = m[0].size();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

void searchZero(const Matrix &m, stack<Pair> &coords) {
    int size = m.size();
    Pair coord;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (m[i][j] == 0) {
                coord.x = i;
                coord.y = j;
                coords.push(coord);
            }
        }
    }
}

void setZeros(Matrix &m, stack<Pair> &coords) {
    int size = m.size();
    Pair coord;
    vector <int> zeros(size, 0);
    while (not coords.empty()) {
        coord = coords.top(); coords.pop();
        m[coord.x] = zeros;
        for (int i = 0; i < size; ++i) {
            m[i][coord.y] = 0;
        }
    }
}

int main () {
    int n = 10;
    Matrix m(n, Line(n));
    fillMatrix(m);

    printMatrix(m);
    cout << endl;

    m[n/2][n/2] = 0;
    m[n/2 - 1][n/2 - 1] = 0;

    stack<Pair> coords;
    searchZero(m, coords);
    setZeros(m, coords);

    printMatrix(m);
 }
