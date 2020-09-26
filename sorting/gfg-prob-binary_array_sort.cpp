// { Driver Code Starts
// A Sample C++ program for beginners with Competitive Programming
#include <iostream>
using namespace std;

void binSort(int A[], int N);


int main() {
	int T;
	cin>>T;
	// Input the number of testcases
	while(T--)
	{
	    int N;
	    cin>>N; //Input size of array N
	    int A[N]; 
	    
	    for(int i = 0; i  < N; i++)
	      cin>>A[i];
	      
	    binSort(A,N);
	    
	    for(int x:A)
	    cout<<x<<" ";
	      
	    cout<<endl;
	}
	return 0;
}



// } Driver Code Ends


// Function to sort the array A[]
// A[]: input array
// N: input array
void binSort(int A[], int N)
{
   //Your code here
   
   // Simple counting
   int count_0 {0};
   int count_1 {0};
   for (int i=0; i<N; ++i) {
       if (A[i]==0) {
           count_0++;
       }
       else {
           count_1++;
       }
   }
   
   int idx = 0;
   for (int i=0; i<count_0; ++i) {
       A[idx] = 0;
       idx++;
   }
   for (int i=0; i<count_1; ++i) {
       A[idx] = 1;
       idx++;
   }
   
   
   /*
   // Using Hoare's partitioning
   int pivot = 1;
   int i = -1;
   int j = N;
   
   while (true) {
       do {
           i++;
       }
       while (A[i]<pivot);
       do {
           j--;
       }
       while (A[j]>=pivot);
       
       if (j<=i) { break; }
      
       //swap
       int t = A[i];
       A[i] = A[j];
       A[j] = t;
   }
   */
   
  
   /**************
    * No need to print the array
    * ************/
}