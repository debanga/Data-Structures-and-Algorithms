/*
Number is sparse or not 
Given a number N. The task is to check whether it is sparse or not. A number is said to be a sparse number if no two or more consecutive bits are set in the binary representation.

Example 1:

Input: N = 2
Output: true
Explanation: Binary Representation of 2 is 10, 
which is not having consecutive set bits. 
So, it is sparse number.
Example 2:

Input: N = 3
Output: false
Explanation: Binary Representation of 3 is 11, 
which is having consecutive set bits in it. 
So, it is not a sparse number.

Your Task: The task is to complete the function checkSparse() that takes n as a parameter and returns true if the number is sparse else returns false.


Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106

*/
#include <bits/stdc++.h>
using namespace std;

// function to check if the number is sparse
// n : is the number to check if it is sparse
bool isSparse(int n){
    
    // Your code
    // Algo- AND n with n>>1, if any 1 then its not sparse
    // but 0's due to 32 bit will coz issue
    int t = (n & (n >> 1));
    if (t!=0) {return false;}
    else {return true;}
}

int main() {
    cout << isSparse(3); // false
}