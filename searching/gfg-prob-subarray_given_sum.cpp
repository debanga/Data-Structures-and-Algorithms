// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
vector<int> subarraySum(int arr[], int n, int s){
    int l = 0;
    int r = 0;
    int count = 0;
    vector<int> res;
    
    while (r<=n) {
        if (count == s) {
            res.push_back(l+1);
            res.push_back(r);
            return res;
        }
        if (l==r || count < s) {
            r++;
            count += arr[r-1];
        }
        else {
            l++;
            count -= arr[l-1];
        }
    }
    
    res.push_back(-1);
    return res;
}


// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        vector<int>res;
        res = subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
