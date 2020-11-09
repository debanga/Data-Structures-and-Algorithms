#include <iostream>
#include <string>
using namespace std;


/** (Naive) LPS helper */
int FindLPSNaive(string str) {
    int len = 0;
    for (int i=0; i<str.length()-1; ++i) {
        for (int j=str.length()-1; j>=0; --j) {
            if (str.substr(0,i+1).compare(str.substr(j,str.length()-j))==0) {
                if (str.substr(0,i+1).length()>len) {
                    len = str.substr(0,i+1).length();
                }
            }
        }
    }
    return len;
}


/** (Naive) Find longest proper prefix suffix */
void PrintLPSNaive(string str) {
    for (int i=0; i<str.length(); ++i) {
        cout << FindLPSNaive(str.substr(0,i+1)) << " ";
    }
    cout << endl;
}


int FindLPS(string str) {
    int len = 0;
    for (int i=0; i<str.length()-1; ++i) {
        if (str.substr(0,i+1).compare(str.substr(str.length()-1-i,i+1))==0) {
            len = i+1;
        }
    }
    return len;
}


void PrintLPS(string str) {
    for (int i=0; i<str.length(); ++i) {
        cout << FindLPS(str.substr(0,i+1)) << " ";
    }
    cout << endl;
}


int main() {
    PrintLPSNaive("abacabad");
    PrintLPSNaive("abbabb");
    cout << FindLPSNaive("abcabc") << endl;

    PrintLPS("abacabad");
    PrintLPS("abbabb");
    cout << FindLPS("abcabc") << endl;
}