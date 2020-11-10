#include <iostream>
#include <string>
#include <vector>
using namespace std;


void Print(vector<int> vec) {
    for (int i=0; i<vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
}


vector<int> FindLPS(string str) {
    int len = 0;
    vector<int> lps;
    lps.push_back(0);

    int i = 1;
    while (i<str.length()) {
        if (str[i]==str[len]) {
            lps.push_back(++len);
            i++;
        }
        else {
            if (len==0) {
                lps.push_back(len);
                i++;
            }
            else {
                len = lps[len-1];
            }
        }
    }
    return lps;
}


void KLM(string str, string ptr, vector<int> lps) {
    int latest_match = 0;
    for (int i=0; i<str.length(); ++i) {
        for (int j=lps[latest_match]; j<ptr.length(); ++j) {
            
            latest_match = ..;
        }
    }
}


int main() {
    string str = "ababcabaaad";
    string str1 = "aaabaaaac";

    Print(FindLPS(str1));

}
