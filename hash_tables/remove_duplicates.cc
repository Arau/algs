#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp (char a, char b)   { return a < b;  }

void remove_duplicate_chars (string &s) {
    sort(s.begin(), s.end(), cmp);
    int j;
    for (int i = 0; i < s.size(); ++i) {
        int size = s.size();
        int count = 0;
        j = i+1;
        while (s[i] == s[i+1] and count < size) {
            s.erase(j, 1);
            ++count;
        }
    }
}

int main () {
    string input;
    while (cin >> input) {
        remove_duplicate_chars(input);
        cout << input << endl;
    }
}
