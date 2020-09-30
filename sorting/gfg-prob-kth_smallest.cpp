#include <iostream>
using namespace std;

int partition(int arr[], int l, int r) {
    int pivot = arr[r];

    int idx = l-1;
    for (int i=l; i<r+1; ++i) {
        if (arr[i]<=pivot) {
            idx++;
            int t = arr[i];
            arr[i] = arr[idx];
            arr[idx] = t;
        }
    }
    return idx;
}

int FindK(int arr[], int l, int r, int k) {
    int n = r-l+1;

    int p = partition(arr, l, r);

    if (p==k-1) {
        return arr[p];
    }
    if (p < k-1) {
        return FindK(arr, p+1,r, k);
    }
    else {
        return FindK(arr, l, p-1, k);
    }
}

int kthSmallest(int arr[], int n, int k) {
    return FindK(arr, 0, n-1, k);
}


int main() {
    int arr[] = {3,5,4,2,9};
    int n = 5;
    int k = 3;
    cout << kthSmallest(arr, n, k) << endl;
    //cout << partition(arr, 0, n-1);
}