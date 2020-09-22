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

// O(n+k)
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


int main() {
    int arr1[] = {1, 4, 4, 1, 0, 1};
    int k1 = 5;
    counting_sort(arr1, 6, k1);
    print_array(arr1, 6);

    int arr2[] = {2, 1, 8, 9, 4};
    int k2 = 10;
    counting_sort(arr2, 5, k2);
    print_array(arr2, 5);
    
}