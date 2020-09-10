/*
Swap all odd and even bits 
Given an unsigned integer N. The task is to swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43(00101011). Here, every even position bit is swapped with adjacent bit on the right side(even position bits are highlighted in the binary representation of 23), and every odd position bit is swapped with an adjacent on the left side.

Example 1:

Input: N = 23
Output: 43
Explanation: 
Binary representation of the given number 
is 00010111 after swapping 
00101011 = 43 in decimal.
Example 2:

Input: N = 2
Output: 1
Explanation: 
Binary representation of the given number 
is 10 after swapping 01 = 1 in decimal.

Your Task: Your task is to complete the function swapBits() which takes an integer and returns an integer with all the odd and even bits swapped.


Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 109
*/

#include <bits/stdc++.h>
#include <cmath>
using namespace std;

// function to swap odd and even bits
unsigned int swapBits(unsigned int n)
{
	// Your code here
	/*
	// right shift and turn off even bits
	unsigned int a = (n >> 1) & int(1*(pow(4,15)-1)/3);
	// left shift and turn off  odd bits
	unsigned int b = (n << 1) & int(2*(pow(4,15)-1)/3);
	// xor to combine (as xor with turned off bit (0) remains same)
	return (a ^ b);
	*/
	// without aux space
	return ((n >> 1) & int(1*(pow(4,15)-1)/3)) ^
	    ((n << 1) & int(2*(pow(4,15)-1)/3));	
}

int main() {
    cout << swapBits(23); // 43
}