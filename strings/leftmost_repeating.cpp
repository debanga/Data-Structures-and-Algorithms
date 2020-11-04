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


int leftmost_repeat_index_1(string str) {
    int map[CHAR];
    fill(map, map+CHAR, -1);

    int min = INT8_MAX;
    int idx = -1;
    for (int i=0; i<str.length(); ++i) {
        if (map[str[i]-'a']==-1) {
            map[str[i]-'a']=i;
        }
        else {
            if (map[str[i]-'a']<min) {
                min = map[str[i]-'a'];
            }
        }
    }
    if (min==INT8_MAX) {
        return -1;
    }
    return min;
}


// Most efficient
int leftmost_repeat_index_2(string str) {
    bool flag[CHAR];
    fill(flag, flag+CHAR, false);

    int min = -1;
    for (int i=str.length()-1; i>=0; --i) {
        if (!flag[str[i]-'a']) {
            flag[str[i]-'a'] = true;
        }
        else {
            min = i;
        }
    }
    return min;
}


int main() {
    string str = "abbced";
    cout << leftmost_repeat_index(str) << endl;
    cout << leftmost_repeat_index_1(str) << endl;
    cout << leftmost_repeat_index_2(str) << endl;
}