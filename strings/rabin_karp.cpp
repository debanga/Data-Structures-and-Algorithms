#include <iostream>
#include <string>
#include <cmath>
using namespace std;


/** Rabin Karp Pattern Matching Algorithm */
void RabinKarpSearch(string str, string ptr) {
    int hash_length = ptr.length();
    int hash_value = 0;
    int ptr_hash = 0;
    int hash_base = 5;
    int hash_modulo = 71;
    for (int i=0; i<hash_length; ++i) {
        hash_value = hash_base*hash_value + str[i];
        ptr_hash = hash_base*ptr_hash + ptr[i];
    }
    hash_value = hash_value % hash_modulo;
    ptr_hash = ptr_hash % hash_modulo;

    if (ptr_hash==hash_value) {
        cout << 0 << " ";
    }

    for (int i=1; i<str.length()-ptr.length()+1; ++i) {
        hash_value = long(hash_base*(hash_value-str[i-1]*pow(hash_base, hash_length-1))
            +(str[i+hash_length-1])) % hash_modulo;
        if (hash_value<0) {hash_value += hash_modulo;}

        if (hash_value==ptr_hash) {
            if (str.compare(i, hash_length, ptr)==0) {
                cout << i << " ";
            }
        }
    }
    cout << endl;
}


int main() {
    string str = "abcdbabcabc";
    string ptr = "abc";
    RabinKarpSearch(str, ptr);
}