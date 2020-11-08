#include <iostream>
#include <iostream>
using namespace std;


void naive_pattern_search(string str, string ptr) {
    for (int i=0; i<str.length()-ptr.length()+1; ++i) {
        if (str.compare(i,ptr.length(),ptr)==0) {
            cout << i << " ";
        }
    }
    cout << endl;
}


void naive_pattern_search_distinct(string str, string ptr) {
    int cnt = 0;
    for (int i=0; i<str.length(); ++i) {
        if (str[i]==ptr[cnt]) {
            cnt++;
            if (cnt==ptr.length()) {
                cout << i-ptr.length()+1 << " ";
                cnt = 0;
            }
        }
        else {
            if (str[i]==ptr[0]) {
                cnt=1;
            }
            else {
                cnt = 0;
            }
        }
    }
    cout << endl;
}


int main() {
    string str = "AAAAAA";
    string ptr = "AAC";
    string str1 = "ABCBCDE";
    string ptr1 = "BCD";

    naive_pattern_search(str, ptr);
    naive_pattern_search_distinct(str1, ptr1);
}