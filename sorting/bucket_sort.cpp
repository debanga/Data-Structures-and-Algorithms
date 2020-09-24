// Bucket sort
#include <iostream>
#include <cmath>
using namespace std;

// print array
void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// insertion sort
void insertion_sort(int arr[], int n) {

}

// bucket sort
void bucket_sort(int arr[], int n) {
    // create bucket spaces

}

int main() {
    int arr[] = {20, 80, 40, 30, 70};
    int n = 5; // number of elements in the array
    int k = 4; // number of buckets

    bucket_sort(arr, n);

    return 0;
}


