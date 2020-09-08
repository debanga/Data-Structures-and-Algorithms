// Check if k-th bit is set or not
#include <iostream>

bool right_shift_algo(int num, int k) {
    return ((num >> (k-1)) & 1);
}

bool left_shift_algo(int num, int k) {
    return ((1 << (k-1)) & num);
}

int main() {
    int num, k;
    std::cin >> num >> k;

    std::cout << right_shift_algo(num, k) << std::endl;
    std::cout << left_shift_algo(num, k) << std::endl;
}