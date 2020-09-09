// Generate power set of a string
#include <iostream>
#include <string>
#include <cmath>

void PrintString(std::string s, int n) {
    int k {1};
    for (int i=0; i<s.length(); ++i) {
        if ((n >> (k-1)) & 1) {
            std::cout << s[i];
        }
        ++k;
    }
    std::cout << " ";
}

// O(2^n * n)
void GeneratePowerset(std::string s) {
    int sz = s.length();
    std::cout << "<NULL> ";
    for (int i=0; i<std::pow(2,sz); ++i) {
        PrintString(s, i);
    }
}



int main() {
    std::string s;
    std::cin >> s;
    GeneratePowerset(s);
}