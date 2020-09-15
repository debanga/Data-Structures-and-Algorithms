// Quick sort implementation with Lomuto partition
#include <iostream>
using namespace std;

// Print array
void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Lomuto partition implementation
int partition_lomuto(int arr[], int l, int h) {
    int pivot {arr[h]};

    int i {l-1};
    
    for (int j=l; j<h+1; ++j) {
        if (arr[j]<=pivot) {
            i++;
            //swap
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    return i;
}

// Quicksort recursion
void quicksort(int arr[], int l, int h) {
    if (l<h) {
        int p = partition_lomuto(arr, l, h);
        cout << "(l,p,h): " << l <<" " << p << " " << h << endl;
        quicksort(arr, l, p-1);
        quicksort(arr, p+1, h);
    }
}

int main() {
    int arr[] = {8, 4, 7, 9, 1, 10, 5};
    quicksort(arr, 0, 6);
    print_array(arr, 7);
}
