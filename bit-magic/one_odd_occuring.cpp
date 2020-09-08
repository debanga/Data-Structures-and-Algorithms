#include <iostream>
#include <vector>
#include <unordered_map>

// Hashing:  O(n), S(n)
int algo1(std::vector<int> nums) {
    std::unordered_map<int, int> umap;
    int x;
    for (auto& e : nums) {
        umap[e]++;
    }
    for (auto& e: umap) {
        if (e.second%2==1) {
            return e.first;
        }
    }
}

// XOR: O(n), S(1)
int algo2(std::vector<int> nums) {
    int x {0};
    for (auto& e : nums) {
        x = (x ^ e);
    }
    return x;
}



int main() {
    std::vector<int> nums = {2, 3, 3, 6, 6, 6, 6, 2, 1};

    std::cout << algo1(nums) << std::endl;
    std::cout << algo2(nums) << std::endl;

}