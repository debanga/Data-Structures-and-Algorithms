// Count set bits of a number in its binary format
#include <iostream>

// Order (32)
int naive(int num) {
    int count {0};
    while (num != 0) {
        count += (num & 1);
        num = num >> 1;
    }
    return count;
}

// Order (number of set bits)
int BrianKernighan(int num) {
    int a {(num & (num-1))};
    int count {0};
    while(a != 0) {
        count++;
        a = (a & (a-1));
    }
    return count+1;
}

// Order (1), given already available lookup table
int Lookup(int num) {
    int table[256] = {0};
    for (int i=1; i<256; ++i) {
        table[i] = (i&1) + table[i/2];
    }
    int count {0};
    count += table[(num & 0xff)];
    num = num >> 8;
    count += table[(num & 0xff)];
    num = num >> 8;
    count += table[(num & 0xff)];
    num = num >> 8;
    count += table[(num & 0xff)];
    return count;
}

int main() {
    int num;
    std::cin >> num;

    std::cout << naive(num) << std::endl;
    std::cout << BrianKernighan(num) << std::endl;
    std::cout << Lookup(num) << std::endl;
    
    return 0;
}