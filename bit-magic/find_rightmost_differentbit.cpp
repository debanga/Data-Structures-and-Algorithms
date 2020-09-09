#include <bits/stdc++.h>
using namespace std;


/*  Function to find the first position with different bits
*   This function returns the position with different bit
*/
int posOfRightMostDiffBit(int m, int n)
{
    
    // Your code here
    int x = (m ^ n);
    int y = (x & ~(x-1));
    if (y==0) {
        return 0;
    }
    else {
        return 1 + (log(y) / log(2)); 
    }
    
}

// { Driver Code Starts.

// Driver code
int main()
{
    // eg.
    // 11 9
    cout << posOfRightMostDiffBit(11, 9); // 2
	return 0;
}
  // } Driver Code Ends