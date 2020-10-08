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


int binary_search0(int arr[], int left, int right, int n, int x) {
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

int binary_search_vanilla(int arr[], int l, int r, int x) {
    int left = l;
    int right = r;
    int mid;

    while(left<=right) {
        mid = left + (right-left)/2;
        if (arr[mid]==x) {
            return mid;
        }
        else if (arr[mid]>x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int search_rotated_sorted(int arr[], int n, int x) {
    int pivot = arr[0];
    int left = 0;
    int right = n-1;
    int mid;

    while (left<=right) {
        mid = left + (right-left)/2;
        if (arr[mid]==x) {return mid;}

        if (arr[mid]>=pivot && x>pivot) {
            return binary_search_vanilla(arr, left, mid-1, x);
        }
        else if (arr[mid]<pivot && x<pivot) {
            return binary_search_vanilla(arr, mid+1, right, x);
        }
        else if (arr[mid]>=pivot) {
            left = mid+1;
        }
        else if (arr[mid]<pivot) {
            right = mid-1;
        }
    }
    return -1;
}



int main() {
    //int arr[] = {10, 20, 30, 50, 60, 8, 9};
    int arr[] = {10, 10, 2, 2, 3};
    int n = 5;
    int x = 4;

    int left = find_left(arr, n);
    int right = left + (n-1);
    //cout << left << " " << right << endl;
    cout << binary_search0(arr, left, right, n, x) << endl;
    cout << search_rotated_sorted(arr, n, x) << endl;

}