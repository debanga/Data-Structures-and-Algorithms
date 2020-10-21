#include <iostream>
using namespace std;


// Find index of a peak element
int peakElement(int arr[], int n)
{
    int l = 0;
    int r = n-1;
    int mid;
    
    while(l<=r) {
        mid = l + (r-l)/2;
        
        if (mid==0) {
            if (arr[mid]>=arr[mid+1]) {
                return 0;
            }
            else {
                l = mid+1;
            }
        }
        else if (mid==n-1) {
            if (arr[mid]>=arr[mid-1]) {
                return n-1;
            }
            else {
                r = mid-1;
            }
        }
        else if (arr[mid] >= arr[mid-1] && arr[mid] >= arr[mid+1] ) {
            return mid;
        }
        else if (arr[mid] <= arr[mid-1]) {
            r = mid-1;
        }
        else if (arr[mid] <= arr[mid+1]) {
            l = mid+1;
        }
    }
}


int main() {
    int arr[] = {9, 14, 10, 10, 1, 2, 1, 7, 10, 10, 14, 19, 9};
    int n = 13;
    cout << peakElement(arr, n) << endl;
}
