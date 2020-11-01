#include <iostream>
#include <string>
using namespace std;


void sort_string(string s) {
    int n = s.size();

    int count[26] = {0};

    for (int i=0; i<n; ++i) {
        count[s[i]-'a']++;
    }

    for (int i=0; i<26; ++i) {
        if (count[i]>0) {
            for (int j=0; j<count[i]; ++j) {
                cout << char(i+'a');
            }
        } 
    }
    cout << endl;
}


int main() {
    string s = "geeksforgeeks";
    sort_string(s);
}