/*
Bit Difference

You are given two numbers A and B. The task is to count the number of bits needed to be flipped to convert A to B.

Example 1:

Input: A = 10, B = 20
Output: 4
Explanation:
A  = 01010
B  = 10100
As we can see, the bits of A that need 
to be flipped are 01010. If we flip 
these bits, we get 10100, which is B.
Example 2:

Input: A = 20, B = 25
Output: 3
Explanation:
A  = 10100
B  = 11001
As we can see, the bits of A that need 
to be flipped are 10100. If we flip 
these bits, we get 11001, which is B.

Your Task: The task is to complete the function countBitsFlip() that takes A and B as parameters and returns the count of the number of bits to be flipped to convert A to B.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ A, B ≤ 106
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find number of bits to be flip
// to convert A to B
int countBitsFlip(int a, int b){
    
    // Your logic here
    // 1- Find how many bits are different
    int t = (a ^ b);
    
    //2- Find how many set bits
    int count {0};
    while (t!=0) {
        t &= t-1;
        ++count;
    }
    return count;
}

int main() {
    cout << countBitsFlip(20, 25); // 3
}