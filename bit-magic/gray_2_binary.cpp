/*
Gray to Binary equivalent 
Given N in Gray code equivalent. Find its binary equivalent. 
Note: We need to find the binary equivalent of the given gray code and return the decimal equivalent of the binary representation.

Example 1:

Input: N = 4
Output: 7
Explanation:
4 is represented as gray 100 and its 
binary equivalent is 111 whose decimal 
equivalent is 7.
Example 2:

Input: N = 15
Output: 10
Explanation:
15 is represented as gray 1111 and its 
binary equivalent is 1010 i.e. 10 in decimal.
Example 3:

Input: N = 0
Output: 0
Explanation: Zero is zero in gray and in
binary and decimal.

Your Task: Your task is to complete the function grayToBinary() which accepts an integer n as a parameter and returns decimal of the binary equivalent of the given gray number. 

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1). 

Constraints:
0 <= N <= 108
*/

#include <bits/stdc++.h>
#include <cmath>

using namespace std;

// function to conver given N Gray to Binary
int grayToBinary(int n)
{
    
    // Your code here
    if (n==0) {return 0;}
    int N = floor(log2(n));
    
    int p = n;
    for (int i=1; i<N+1; ++i) {
        p = p ^ (n >> i);    
    }
    return p;
    
}

int main() {
    cout << grayToBinary(118428032); //100000000
}