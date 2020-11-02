#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main() {
    char str[] = "gfg";
    cout << str << endl;
    cout << sizeof(str) << endl;

    char str1[] = {'i','f','g', '\0'};
    cout << sizeof(str1) << endl;
    cout << str1 << endl;

    cout << strlen(str) << endl;
    cout << strcmp(str, str1) << endl;

    char str2[4];
    strcpy(str2, str1);
    cout << str2 << endl;

    string s = "geeksforgeeks";
    cout << s.substr(2,4) << endl;
    cout << s.find("for") << endl;
    cout << s.find("fir") << endl;
    cout << s.find("fir0") << endl;

}