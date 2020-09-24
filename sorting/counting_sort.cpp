// Counting sort
// O(n+k)

#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Naive: O(n+k) object identity not preserved
//
void counting_sort(int arr[], int n, int k) {
    int count_arr[k];

    // O(k)
    for (int i=0; i<k; ++i) {
        count_arr[i] = 0;
    }

    // O(n)
    for (int i=0; i<n; ++i) {
        count_arr[arr[i]]++;
    }

    // O(n+k)
    int idx {0};
    for (int i=0; i<k; ++i) {
        for (int j=0; j<count_arr[i]; ++j) {
            arr[idx] = i;
            idx++;
        }
    }
}

// Object-preserving counting sort: 
// Sorts real objects rather than just repeated adding
// O(n+k), S(n+k)
void counting_sort2(int arr[], int n, int k) {
    int count_arr[k];
    for (int i=0; i<k; ++i) {
        count_arr[i] = 0;
    }

    // count: O(n)
    for (int i=0; i<n; ++i) {
        count_arr[arr[i]]++;
    }

    // integrate count_arr
    for (int i=1; i<k; ++i) {
        count_arr[i] = count_arr[i] + count_arr[i-1]; 
    }

    // O(n+k)
    int output[n]; // S(n)
    for (int i=n-1; i>=0; --i) {
        int d = arr[i];
        int idx = count_arr[d] - 1;
        count_arr[d]--;

        output[idx] = arr[i]; // so we are putting actual value
            // instead of just repeated adding of numbers
    }

    // copy to original array
    for (int i=0; i<n; ++i) {
        arr[i] = output[i];
    }
}

int main() {
    int arr1[] = {1, 4, 4, 1, 0, 1};
    int k1 = 5;
    cout << "Example 1" << endl;
    counting_sort2(arr1, 6, k1);
    print_array(arr1, 6);
    cout << endl;

    int arr2[] = {2, 1, 8, 9, 4, 8};
    int k2 = 10;
    cout << "Example 2" << endl;
    counting_sort2(arr2, 6, k2);
    print_array(arr2, 6);

    int arr3[] = {0, 1, 0, 0, 1, 0, 1};
    int k3 = 2;
    cout << "Example 2" << endl;
    counting_sort2(arr3, 7, k2);
    print_array(arr3, 7);
}