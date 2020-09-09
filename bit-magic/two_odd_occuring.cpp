// From a array of unsorted integer array, find the only two integers with
// odd number of occurances
#include <iostream>
#include <vector>

// Check if k-th bit is set
bool CheckSet(int m, int k) {
    return ((m >> (k-1)) & 1);
}

// XOR Bucket: O(2n), S(1)
void twoodds(std::vector<int> nums) {
    // Do XOR of all elements
    int x {0};
    for (auto& v : nums) {
        x = (x ^ v);
    }

    // Find set key
    int k {1};
    while (!CheckSet(x, k)) {
        k++;
    }
    
    // Group formation
    int g1 {0}, g2{0};
    for (auto& v : nums) {
        if (CheckSet(v, k)) { g1 = g1 ^ v; }
        else {g2 = g2 ^ v; }
    }

    // Output
    std::cout << g1 << " " << g2;
}


int main() {
    std::vector<int> nums = {9, 3, 3, 4, 4, 6, 6, 5, 5, 5, 5, 5};
    twoodds(nums);
}
