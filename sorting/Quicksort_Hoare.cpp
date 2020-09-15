// Quicksort using Hoare partition
#include <iostream>
using namespace std;

// Print array
void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition_hoare(int arr[], int l, int h) {
    int pivot {arr[l]};

    int i {l-1}, j {h+1};
    while(true) {
        do {
            i++;
        }
        while(arr[i]<pivot);

        do {
            j--;
        }
        while(arr[j]>pivot);
        if (i>=j) {return j;}
        // swap
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

void quicksort(int arr[], int l, int h) {
    if (l<h) {
        int k = partition_hoare(arr, l, h);
        quicksort(arr, l, k);
        quicksort(arr, k+1, h);
    }
}

int main() {
    int arr[] = {8, 4, 7, 9, 3, 10, 5};
    quicksort(arr, 0, 6);
    print_array(arr, 7);
}