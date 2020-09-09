/*
Longest Consecutive 1's

Given a number N. The task is to find the length of the longest consecutive 1s in its binary representation.

Example 1:

Input: N = 14
Output: 3
Explanation: Binary representation of 14 is 
1110, in which 111 is the longest consecutive 
set bits of length is 3.
Example 2:

Input: N = 222
Output: 4
Explanation: Binary representation of 222 is 
11011110, in which 1111 is the longest 
consecutive set bits of length 4. 

Your Task: The task is to complete the function maxConsecutiveOnes() which returns the length of the longest consecutive 1s in the binary representation of given N.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 <= N <= 106
*/

#include <bits/stdc++.h>
using namespace std;

/*  Function to calculate the largest consecutive ones
*   x: given input to calculate the largest consecutive ones
*/
int maxConsecutiveOnes(int x)
{
 
    // Your code here
    // Naive
    /*
    int max {0};
    int t {0};
    int c {0};
    for (int i=0; i<32; ++i) {
        int a = (x >> i) & 1;
        
        if (a==1 && t==0) {++c;}
        if (a==1 && t==1) {++c;}
        if (a==0 && t==1) {
            if (c>max) {max = c;}
            c = 0;
        }
        
        t = a;
    }
    return max;
    */
    
    // Smarter
    int count {0};
    while (x!=0) {
        x = x & (x >> 1);
        count++;
    }
    return count;
}



int main() {
    cout << maxConsecutiveOnes(222); // 4
}