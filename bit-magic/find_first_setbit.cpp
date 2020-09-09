// { Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function Template for C++

/*  function to find position of first set 
    bit in the given number
 * n: given input for which we want to get
      the position of first set bit
 */
unsigned int getFirstSetBit(int n){
    
    // Your code here
    int c = 1;
    int k {1};
    int m;
    
    switch (c) {
        case 0:
            for (int i=8*sizeof(n)-1; i>=0; --i) {
                if ((n >> (k-1)) & 1) {return k;}
                ++k;
            }
            return 0;
            break;    
        
        case 1:
            // create last set bit mask
            m = n & ~(n-1);
            // search which bit is set
            if (m==0) {
                return 0;
            }
            else {
                return 1 + (log(m) / log(2));
            }
        
    }
    
}

// { Driver Code Starts.

// Driver code
// { Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        printf("%u\n", getFirstSetBit(n)); // function to get answer
    }
	return 0;
}
  // } Driver Code Ends