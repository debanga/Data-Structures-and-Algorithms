// Find kth smallest element in an array, no duplicates, non-zero integers
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int r) {
    // Lomuto partition
    int i {l-1};
    int pivot {arr[r]};

    for (size_t j=l; j<r+1; ++j) {
        if (arr[j] <= pivot) {
            i++;
            // swap
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }
    return i;
}


// Naive
int find_kth_smallest1(int arr[], int k, int n) {
    sort(arr, arr+n); // O(nlogn)
    return arr[k-1];
}

// Using partition
int find_kth_smallest2(int arr[], int k, int l, int r) {
    int p {partition(arr, l, r)};
    if ( p == k-1) {
        return arr[p];
    }
    else {
        if (p<k-1) {
            return find_kth_smallest2(arr, k, p+1, r);
        }
        else {
            return find_kth_smallest2(arr, k, l, p-1);
        }
    }
}


int main() { 
    int arr[] {5, 11, 30, 12};
    int arr2[] = {10, 4, 5, 8, 11, 6, 26};
    int k = 2;
    cout << find_kth_smallest1(arr, k, 4) << endl;
    cout << find_kth_smallest2(arr, k, 0, 3) << endl;
    cout << find_kth_smallest1(arr2, 4, 6) << endl;
    cout << find_kth_smallest2(arr2, 4, 0, 6) << endl;
}
