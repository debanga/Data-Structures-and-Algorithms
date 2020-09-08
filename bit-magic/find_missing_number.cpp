// A n-1 length array where all integers in [1, n] exists once except one of the numbers.
// Find that number.

#include <iostream>
#include <vector>

// XOR: O(N), S(1)
int algo1(std::vector<int> nums) {
    int N = nums.size()+1;
    int x {1};
    for (int i=0; i<nums.size(); ++i) {
        x = x ^ (i+2) ^ nums[i];
    }
    return x;

}

int main() {
    std::vector<int> nums = {1, 2, 3, 5};

    std::cout << algo1(nums) << std::endl;
}