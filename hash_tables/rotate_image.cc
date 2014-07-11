#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>  Line;
typedef vector<Line> Matrix;

void fillMatrix (Matrix &m) {
    int size = m[0].size();
    int counter = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            //m[i][j] = i*10 + j;
            m[i][j] = counter;
            ++counter;
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

void rotateMatrixHalfPi (Matrix &m) {
    int size = m[0].size();
    int last = size - 1;
    int newI, newJ, aux1, aux2, curI, curJ;
    for (int i = 0; i < size/2; ++i) {
        for (int j = i; j < last - i; ++j) {

            // First move
            newI = last - j;
            newJ = i;

            aux1 = m[newI][newJ];
            m[newI][newJ] = m[i][j];

            // Second move
            curI = newI; curJ = newJ;
            newI = last - i;
            newJ = last - j;

            aux2 = m[newI][newJ];
            m[newI][newJ] = aux1;


            // Third move
            curI = newI; curJ = newJ;
            newI = j;
            newJ = last - i;

            aux1 = m[newI][newJ];
            m[newI][newJ] = aux2;


            // Fourth move
            curI = newI; curJ = newJ;
            newI = i;
            newJ = j;

            m[newI][newJ] = aux1;
        }
    }
}

int main () {
    Matrix m(5, Line(5));
    fillMatrix(m);
    printMatrix(m);
    cout << endl;
    rotateMatrixHalfPi(m);
    printMatrix(m);
}
