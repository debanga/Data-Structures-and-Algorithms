// Bubble sort
// O(N^2)
#include <bits/stdc++.h>
using namespace std;

void bubble(int arr[], int N) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N-1-i; ++j) {
            if (arr[j]>arr[j+1]) {
                arr[j]   = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j]   = arr[j]^arr[j+1];
            }
        }
    }
}

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {4,1,3,9,2};
    bubble(arr, 5);
    print(arr, 5);
}
