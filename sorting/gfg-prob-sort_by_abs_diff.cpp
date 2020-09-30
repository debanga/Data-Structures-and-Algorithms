#include <iostream>
#include <cmath>
using namespace std;

void print_array(int A[], int N) {
    for (int i=0; i<N; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int brr[], int l, int mid, int r) {
    int i = l;
    int j = mid+1;

    int res[r-l+1];
    int res1[r-l+1];

    int idx = 0;
    while (i<=mid && j<=r) {
        if (brr[i]<=brr[j]) {
            res[idx] = arr[i];
            res1[idx] = brr[i]; 
            idx++;
            i++;
        }
        else {
            res[idx] = arr[j]; 
            res1[idx] = brr[j];
            idx++;
            j++;
        }
    }
    while (i<=mid) {
        res[idx] = arr[i]; 
        res1[idx] = brr[i];
        idx++;
        i++;
    }
    while (j<=r) {
        res[idx] = arr[j]; 
        res1[idx] = brr[j];
        idx++;
        j++;
    }

    for (int i=0; i<(r-l+1); ++i) {
        arr[i+l] = res[i];
        brr[i+l] = res1[i];
    }

    /*
    for (int i=0; i<(r-l+1); ++i) {
        cout << arr[i] << " ";
    }
    */
}

void mergeSort(int arr[], int brr[], int l, int r) {
    int mid = l + (r-l)/2;

    if (l<r) {
        mergeSort(arr, brr, l, mid);
        mergeSort(arr, brr, mid+1, r);
        merge(arr, brr, l, mid, r);
    }
}


// Function to sort the given array according to
// the difference with K
// A[]: input array
// N: size of array
void sortABS(int A[], int N, int k)
{
    int B[N];

    for (int i=0; i<N; ++i) {
        B[i] = abs(A[i]-k);
    }
    mergeSort(A, B, 0, N-1);
}

int main() {
    int arr[] = {10, 5, 3, 9, 2};
    int N = 5;
    int K = 7;
    sortABS(arr, N, K);
    print_array(arr, N);
}