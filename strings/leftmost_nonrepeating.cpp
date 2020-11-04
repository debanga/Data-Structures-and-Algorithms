#include <iostream>
#include <string>
using namespace std;

const int CHAR = 256;


int leftmost_nonrepeating(string str) {
    int count[CHAR] = {0};

    for (int i=0; i<str.length(); ++i) {
        count[str[i]]++;
    }

    for (int i=0; i<str.length(); ++i) {
        if (count[str[i]]==1) {
            return i;
        }
    }
    return -1;
}


int leftmost_nonrepeating_1(string str) {
    int flag[CHAR];
    fill(flag, flag+CHAR, -1);

    for (int i=0; i<str.length(); ++i) {
        if (flag[str[i]]==-1) {
            flag[str[i]] = i;
        }
        else {
            flag[str[i]] = -2;
        }
    }

    int min = INT8_MAX;
    for (int i=0; i<CHAR; ++i) {
        if(flag[i]<min && flag[i]>=0) {
            min = flag[i];
        }
    }
    if (min==INT8_MAX) {
        return -1;
    }    
    return min;
}


int main() {
    string str = "geeksforgeeks";
    cout << leftmost_nonrepeating(str) << endl;
    cout << leftmost_nonrepeating_1(str) << endl;
}