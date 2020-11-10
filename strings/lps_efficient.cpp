#include <iostream>
#include <string>
using namespace std;

void FindLPS(string str) {
    int lps[str.length()];
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i<str.length()) {
        if (str[i]==str[len]) {
            lps[i] = ++len;
            i++;
        }
        else {
            if (len==0) {
                lps[i] = 0;
                i++;
            }
            else {
                len = lps[len-1];
            }
        }
    }

    for (int i=0; i<str.length(); ++i) {
        cout << lps[i] << " ";
    }
    cout << endl;

}


int main() {
    string str = "aaabaaaac";
    FindLPS(str);

}