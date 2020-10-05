#include <iostream>
using namespace std;


int binary_search(int arr[], int n, int x) {
    int l = 0;
    int r = n-1;
    int mid;

    while (l<=r) {
        mid = l + (r-l)/2;
        if (arr[mid]==x) { return mid; }
        else if (arr[mid]<x) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return -1;
}


int find_first_occurance(int arr[], int n, int x) {
    int idx;
    int res = binary_search(arr, n, x);
    if ( res == -1) {
        return -1;
    }
    else {
        int l = 0;
        int r = res-1;
        int mid;
        idx = res;
        while (l<=r) {
            mid = l + (r-l)/2;
            if (arr[mid]==x) {
                idx = mid;
                r = mid - 1;
            }
            else if (arr[mid]<x) {
                l = mid+1;
            }
        }
        return idx;
    }
}


int main() {
    int arr[] = {1, 10, 10, 10, 20, 20, 40};
    int n = 7;
    int x = 20;
    cout << find_first_occurance(arr, n, x) << endl;

}


