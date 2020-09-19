// You need to segregate an array of elements containing three types of elements. The types are:
// Sort an array of 0s, 1s, 2s.
// Three-way partitioning when multiple occurrences of a pivot may exist.
// Partitioning around a range.

#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}   

void three_partition(int arr[], int n, int rl, int rh) {
    int i {-1}, ii {-1};
    int j {n}, jj {n};

    while (true) {
        do {
            if (j==0) {break;}
            j--;
        }
        while (arr[j]>rh);
        jj = j;
        do {
            if (jj==0) {break;}
            jj--;
        }
        while(arr[jj]<(rh+1));

        if (jj==0) {break;}
        // swap
        cout << " " << arr[j] << " " << arr[jj] << " " << endl;
        int t = arr[j];
        arr[j] = arr[jj];
        arr[jj] = t;   

    }
    print_array(arr, 8);
    
    while (true) {
        do {
            if (i==n-1) {break;}
            i++;
        }
        while (arr[i]<rl || arr[i]>rh);
        ii = i;
        do {
            if (ii==n-1) {break;}
            ii++;
        }
        while(arr[ii]>rl);

        if (ii==n-1) {break;}
        // swap
        int t = arr[i];
        arr[i] = arr[ii];
        arr[ii] = t;
    }
    print_array(arr, 8);
}


int main() {
    int arr[] = {2, 11, 2, 12, 10, 20, 10, 30};

    three_partition(arr, 8, 10, 12);
    print_array(arr, 8);
}