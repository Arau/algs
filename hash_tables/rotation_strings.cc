#include <iostream>
#include <string>

using namespace std;

bool isSubstring (string s1, string s2) {
    return s1.find(s2) != string::npos;
}

int nextOcurr (string s, char c, int offset) {
    for (int i = offset; i < s.length(); ++i) {
        if (s[i] == c) return i;
    }
    return -1;
}

bool isRotation (string s1, string s2) {
    int size = s2.length();
    if (s1.length() != size) return false;

    int index = nextOcurr(s2, s1[0], 0);
    int i = index + 1;
    while (i < size) {
        cout << " i " << i << endl;
        if (s1[i - index] != s2[i]) {
            index = nextOcurr(s2, s1[0], i);
            i = index+1;
            if (index == -1)
                return false;
        } else {
            ++i;
        }
        cout << endl;
    }
    return isSubstring(s1, s2.substr(0, index-1));
}

int main () {
    string s1, s2;
    while (cin >> s1 >> s2) {
        cout << s1 << ' ' << s2 << endl;
        if (isRotation(s1,s2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}
