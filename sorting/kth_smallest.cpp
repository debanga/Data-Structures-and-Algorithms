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

// Using partition: Quickselect
// Note: can be further optimized using tail call allimination, see @geeks4geeks
// Note: the order of the original array is changed, if you want to keep the 
// original array you have to copy
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

// Tail call optimized
int find_kth_smallest3(int arr[], int k, int l, int r) {

    while(l<r) {
        int p {partition(arr, l, r)};
        if ( p == k-1) {
            return arr[p];
        }
        else {
            if (p<k-1) {
                l = p+1;
            }
            else {
                r = p-1;
            }
        }
    }
    return -1; // not present
}


int main() { 
    int arr[] {5, 11, 30, 12};
    int arr2[] = {10, 4, 5, 9, 11, 6, 26};
    int k = 2;
    // Naive
    cout << find_kth_smallest1(arr, k, 4) << endl;

    // Using partition (without tail call ellimination)
    cout << find_kth_smallest2(arr2, 4, 0, 6) << endl;

    // Using partition (using tail call ellimination)
    cout << find_kth_smallest3(arr2, 4, 0, 6) << endl;
}
