#include <iostream>
#include <string>
using namespace std;

const int CHAR = 256;


int leftmost_repeat_index(string str) {
    int count[CHAR] = {0};

    for (int i=0; i<str.length(); ++i) {
        count[str[i]-'a']++;
    }

    for (int i=0; i<str.length(); ++i) {
        if (count[str[i]-'a']>1) {
            return i;
        }
    }
    return -1;
}


int main() {
    string str = "abcdedd";
    cout << leftmost_repeat_index(str) << endl;
}