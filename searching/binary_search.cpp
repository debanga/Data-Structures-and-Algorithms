#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int l, int r, int x) {
    if (l>r) {
        return -1;
    }

    int mid = l + (r-l)/2;

    if (arr[mid] == x) {
        return mid;
    }

    if (arr[mid]>x) {
        return binary_search(arr, n, l, mid-1, x);
    }
    else {
        return binary_search(arr, n, mid+1, r, x);
    }

}

int binary_search_iter(int arr[], int n, int x) {
    int l = 0;
    int r = n-1;

    while (l<=r) {
        int mid = l + (r-l)/2;
        if (arr[mid]==x) {
            return mid;
        }
        if (arr[mid]>x) {
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }

    return -1;

}


int main() {
    int arr[] = {10, 20, 30, 40, 40, 60};
    int n1 = 6;
    //cout << binary_search(arr, n1, 0, n1-1, 40) << endl;

    int arr1[] = {10, 10};
    int n2 = 2;
    cout << binary_search(arr1, n2, 0, n2-1, 100) << endl;

    cout << binary_search_iter(arr, n1, 30) << endl;
}