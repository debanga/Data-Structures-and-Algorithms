// Segregate an array into 2 parts (left part, right part), based on two types. 
// Order does not matter
// Question comes with different variations based on types
// 1- positive vs negative
// 2- even vs odd
// 3- 0 vs 1
// Note: should be finished in one traversal
#include <iostream>
using namespace std;

// print array
void print_array(int arr[], int N) {
    for (size_t i=0; i<N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// algo1
void segregate_sign(int arr[], int N) {
    int i {-1}, j {N};

    while(true) {
        do {
            i++;
        }
        while (arr[i]<=0);

        do {
            j--;
        }
        while (arr[j]>0);

        if (i>=j) {break;}
        // swap
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

// algo1
void segregate_odd(int arr[], int N) {
    int i {-1}, j {N};

    while(true) {
        do {
            i++;
        }
        while (arr[i]%2==0);

        do {
            j--;
        }
        while (arr[j]%2==1);

        if (i>=j) {break;}
        // swap
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
    }
}

int main() {
    int arr[] {15, -3, -2, 16};
    int arr2[] {15, -3, 1, -3, 0, 16, -19};
    int arr3[] {15, 3, 100, 12, 0, 16, 19};
    segregate_sign(arr2, 7);
    print_array(arr2, 7);
    segregate_odd(arr3, 7);
    print_array(arr3, 7);

}
