#include <iostream>
using namespace std;

int find_last_occurance(int arr[], int n, int x) {
    int l = 0;
    int r = n-1;
    int mid;
    while(l<=r) {
        mid = l + (r-l)/2;
        if (arr[mid]>x) {
            r = mid-1;
        }
        else if (arr[mid]<x) {
            l = mid+1;
        }
        else {
            if (mid==n-1 || (arr[mid]!=arr[mid+1])) {
                return mid;
            }
            else {
                l = mid+1;
            }
        }
    }
    return -1;
}


int main() {
    int arr[] = {2, 14, 10, 10, 12};
    int n = 5;
    int x = 10;
    cout << find_last_occurance(arr, n, x) << endl;
}