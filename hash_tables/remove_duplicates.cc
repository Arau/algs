#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

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

// Assume that we have an array with numbers between 1-N where
// N is at most 32.000. We have 4KB mem available
void remove_duplicate_num (const vector<int>& v) {
    int bools[32000];
    for (int i = 0; i < v.size(); ++i) {
        if (bools[ v[i] ] == 1) {
            cout << v[i] << endl;
            // Remove num
        } else {
            bools[ v[i] ] = 1;
        }
    }
}

int main () {
    string input;
    cin >> input;
    remove_duplicate_chars(input);
    cout << input << endl;

    int size;
    cout << "Size: ";
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; ++i) cin >> nums[i];


    remove_duplicate_num(nums);
}
