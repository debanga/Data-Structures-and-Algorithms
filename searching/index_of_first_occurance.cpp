#include <iostream>
using namespace std;


int binary_search(int arr[], int n, int x) {
 
}


int find_first_occurance(int arr[], int n, int x) {
    int l = 0;
    int r = n-1;
    int mid;
    while (l<=r) {
        mid = l + (r-l)/2;
        if (arr[mid]<x) {
            l = mid+1;
        }
        else if (arr[mid]>x) {
            r = mid-1;
        }
        else if (arr[mid] == x) {
            if (mid==0 || !(arr[mid]==arr[mid-1])) {
                return mid;
            }
            else {
                r = mid-1;
            }
        }
    }
    return -1;
}


int main() {
    int arr[] = {10, 20};
    int n = 2;
    int x = 20;
    cout << find_first_occurance(arr, n, x) << endl;

}


