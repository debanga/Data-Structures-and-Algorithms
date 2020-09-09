/*
Count total set bits 

You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Example 1:

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.
Example 2:

Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), 
the total number of set bits is 35.

Your Task: The task is to complete the function countSetBits() that takes n as a parameter and returns the count of all bits.

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106

*/

#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    // Your logic here
    /* NAIVE
    int tot {0};
    for (int i=1; i<= n; ++i) {
        int count {0};
        int N = i;
        while (N!=0) {
            N = N & (N-1);
            count++;
        }
        tot += count;
    }
    return tot;
    */
    
    // Count per bit: how many 1s possible for a perticular number n
    int count {0};
    int p = log2(n)+1; // max bits needed
    for (int k=1; k<=p; ++k) { // count 1's per bit
        int a = (n+1) % int(pow(2,k));
        count += pow(2,k-1)*(floor((n+1) / pow(2,k))) // 1's till latest 2^N format number
            +  (a > pow(2,k-1) ? a % int(pow(2,k-1)) : 0); // 1's after latest 2^N number
                                                            // to the given number
    }
    return count;   
}

int main() {
    cout << countSetBits(17) << endl;
}