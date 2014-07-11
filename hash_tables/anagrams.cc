#include <iostream>
#include <string>
#include <map>

using namespace std;

bool anagram (string s1, string s2) {
    if (s1.size() != s2.size()) return false;
    if (s1.empty())             return false;

    map<char, int> s1_counter, s2_counter;
    char c;
    for (int i = 0; i < s1.size(); ++i) {
        c = s1[i];
        if (s1_counter.find(c) != s1_counter.end()) {
            // Found character c as a key in map
            s1_counter[c] += 1;
        } else {
            s1_counter[c] = 1;
        }
    }

    for (int j = 0; j < s2.size(); ++j) {
        c = s2[j];
        // check if exists in the s1 map
        if (s1_counter.find(c) != s1_counter.end()) {
            // Found in s1 map
            if (s2_counter.find(c) != s2_counter.end()) {
                // Found in s2 map
                if (s2_counter[c] == s1_counter[c]) {
                    return false;
                } else {
                    s2_counter[c] += 1;
                }
            } else {
                // No exists in s2 map
                s2_counter[c] = 1;
            }
        } else {
            return false;
        }
    }
    return true;
}

int main () {
    string s1, s2;
    while (cin >> s1 >> s2) {
        if (anagram(s1,s2)) cout << " Yes " << endl;
        else cout << " No " << endl;
    }
}
