#include <iostream>
#include <string>
using namespace std;

const int CHAR = 256;


// Check if two strings are anagrams
bool check_anagram(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    int count[CHAR] = {0};

    for (auto x : s1) {
        count[x-'a']++;
    }

    for (auto x : s2) {
        count[x-'a']--;
    }

    for (int i=0; i<26; ++i) {
        if (count[i]!=0) {
            return false;
        }
    }
    return true;
}


int main() {
    string s1 = "listen";
    string s2 = "silent";
    cout << check_anagram(s1, s2) << endl;
}