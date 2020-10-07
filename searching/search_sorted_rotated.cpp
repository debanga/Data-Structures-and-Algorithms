#include <iostream>
using namespace std;

int find_left(int arr[], int n) {
    if (arr[0]<=arr[n-1]) {
        return 0;
    }

    int l = 0;
    int r = n-1;
    int mid;
    int pivot = arr[0];

    while(l<=r) {
        mid = l + (r-l)/2;
        if (arr[mid]<pivot && (arr[mid-1]>arr[mid])) {
            return mid;
        }
        if (arr[mid]>=pivot) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return 0;
}


int binary_search(int arr[], int left, int right, int n, int x) {
    int l = left;
    int r = right;
    int mid;

    while(l<=r) {
        mid = (l + (r-l)/2);
        if (arr[mid%n]==x) {
            return mid%n;
        }
        else if(arr[mid%n]<x) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    return -1;
}


int main() {
    //int arr[] = {10, 20, 30, 50, 60, 8, 9};
    int arr[] = {10, 10, 2, 2, 3};
    int n = 5;
    int x = 10;

    int left = find_left(arr, n);
    int right = left + (n-1);
    //cout << left << " " << right << endl;
    cout << binary_search(arr, left, right, n, x) << endl;

}