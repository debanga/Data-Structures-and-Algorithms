#include <iostream>
using namespace std;

int first_occurance(int arr[], int n, int x) {
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
        else {
            if (mid==0 || (arr[mid]!=arr[mid-1])) {
                return mid;
            }
            else {
                r = mid-1;
            }
        }
    }

    return -1;
}

int last_occurance(int arr[], int n, int x) {
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
    int arr[] = {10, 20, 20, 21, 30};
    int n = 5;
    int x = 20;
    int count = 0;

    int first = first_occurance(arr, n, x);
    if (first==-1) {
        count = 0;
    }
    else {
        count = last_occurance(arr, n, x) - first + 1;
    }

    cout << count << endl;
}