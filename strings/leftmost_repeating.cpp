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
    int count[CHAR] = {0};
    int map[CHAR];
    fill(map, map+CHAR, -1);

    for (int i=0; i<str.length(); ++i) {
        if (map[str[i]-'a']==-1) {
            map[str[i]-'a']=i;
        }

        count[str[i]-'a']++;
    }

    int min = 100000;
    int idx = -1;
    for (int i=0; i<str.length(); ++i) {
        if (count[i]>1 && map[i]<min) {
            min = map[i];
            idx = i;
        }
    }
    if (idx>-1) {
        return idx;
    }
    return -1;
}


int main() {
    string str = "abbdedd";
    cout << leftmost_repeat_index(str) << endl;
    cout << leftmost_repeat_index_1(str) << endl;
}