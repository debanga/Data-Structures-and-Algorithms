#include <iostream>
#include <string>
using namespace std;


void sortedchar_frequency(string s) {
    int n = s.size();

    int arr[26];
    for (int i=0; i<26; i++) {
        arr[i] = 0;
    }

    for (int i=0; i<n; ++i) {
        arr[s[i]-97]++;
    }

    for (int i=0; i<26; ++i) {
        if (arr[i]!=0) {
            cout << char(i+97) << " " << arr[i] << endl;
        }
    }
}


int main() {
    string s = "geeksforgeeks";
    sortedchar_frequency(s);
}