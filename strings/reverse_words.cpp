#include <iostream>
#include <string>
#include <vector>
using namespace std;


string swap_characters(string& str, int start, int end) {
    for (int i=start; i<=start+(end-start)/2; ++i) {
        int t = str[i];
        str[i] = str[end+start-i];
        str[end+start-i] = t;
    }
    return str;
}


void print_vector(vector<int> v) {
    cout << v.size() << endl;;
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}


string reverse_words(string str) {
    int l = 0;
    for (int i=0; i<str.length(); ++i) {
        if (str[i]==' ') {
            swap_characters(str, l, i-1);
            l = i+1;
        }
    }
    swap_characters(str, l, str.length()-1);

    swap_characters(str, 0, str.length()-1);

    return str;
}


int main() {
    string str = "I love coding very much!";
    cout << reverse_words(str) << endl;
}