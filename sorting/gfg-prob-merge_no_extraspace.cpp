#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// O(n*m*log(m)) or O(m*n)
void merge0(int arr1[], int arr2[], int n, int m) 
{ 

    int j = 0;
    for (int i=0; i<n; ++i) {
        if (arr1[i] > arr2[j]) {
            // swap
            int t = arr2[j];
            arr2[j] = arr1[i];
            arr1[i] = t;

            // sort array2
            sort(arr2,arr2+m);
            // Note: This can be further optimized by shifting and
            // putting it in the right place which is O(m) rather
            // than sorting which is O(mlog(m))
        }
    }
    
} 


// O((n+m)*log(n+m)): @todo: comb sort
void merge(int arr1[], int arr2[], int n, int m) 
{ 
    
} 

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = 4;
    int m = 5;

    merge(arr1, arr2, n, m);
    print_array(arr1, n);
    print_array(arr2, m);
}