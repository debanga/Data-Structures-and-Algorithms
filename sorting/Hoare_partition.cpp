// Hoare Partition
#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int hoare_partition(int arr[], int n) {
    int i {-1}, j {n};
    int pivot = arr[0];

    while(true) {
        do {
            i++;
        }
        while(arr[i]<pivot);

        do {
            j--;
        }
        while(arr[j]>pivot);
        if (j<=i) {return j;}
        
        // swap
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int main() { 
    int a;
    int arr[] = {10, 11, 9, 6, 12, 19};
    a = hoare_partition(arr, 6);
    print_array(arr, 6);

    // corner cases
    int arr1[] = {10, 9, 8, 7};
    a = hoare_partition(arr1, 4);
    print_array(arr1, 4);

    int arr2[] = {7, 8, 9, 10};
    a = hoare_partition(arr2, 4);
    print_array(arr2, 4);

    int arr3[] = {10, 10, 10, 10};
    a = hoare_partition(arr3, 4);
    print_array(arr3, 4);

}