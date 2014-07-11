#include <iostream>
#include <string>
#include <map>

using namespace std;



bool uniq_chars_aux_data_struct (string s) {
    map <char, int> uniq;
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (uniq.find(c) == uniq.end())
            // Not exists
            uniq[c] = 1;
        else
            return false;
    }
    return true;
}

bool is_in(string word, char c, int i) {
    for (int j = i; j < word.size(); ++j) {
        if (word[j] == c) return true;
    }
    return false;
}

bool uniq_chars_no_data_struct(string word) {
    for (int i = 0; i < word.size(); ++i) {
        char c = word[i];
        if (is_in(word, c, i+1))
            return false;
    }
    return true;
}

int main() {
    int flag; // 0 aux data struct, 1 otherwise
    cout << "Input flag" << endl;
    cin >> flag;
    bool uniq;
    string word;
    cout << "Input word" << endl;
    while (cin >> word) {
        if (flag == 0)
            uniq = uniq_chars_aux_data_struct(word);
        else
            uniq = uniq_chars_no_data_struct(word);

        if (uniq)
            cout << "Uniq" << endl;
        else
            cout << "No uniq" << endl;
    }
}
