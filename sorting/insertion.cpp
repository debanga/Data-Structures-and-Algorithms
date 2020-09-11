// Insertion sort
// Popular O(N^2)
#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void insertion(int arr[], int n) {
    for (int i=1; i<n; ++i) {
        int key = arr[i];
        for (int j=i-1; j>=0; --j) {
            if (arr[j]>key) {
                arr[j+1] = arr[j];
                if (j==0) {
                    arr[0] = key;
                }
            }
            else {
                arr[j+1] = key;
                break;
            }
        }
    }
}

int main() {
    int arr[] = {4,1,3,9,2};
    insertion(arr, 5);
    print(arr, 5);
}
