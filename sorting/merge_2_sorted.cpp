#include <iostream>

using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int arr1[], int arr2[], int m, int n) {
    for (int i=0; i<m; ++i) {
        if (arr1[i]>arr2[0]) {
            //swap
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;

            // update arr2
            int key = arr2[0];
            for (int j=1; j<n; ++j) {
                if (key<=arr2[j]) {
                    arr2[j-1] = key;
                    break;
                }
                else {
                    arr2[j-1] = arr2[j];
                    if (j==n-1) {
                        arr2[j] = key;
                    }
                }
            }
        }
    }
}

int main() {
    int arr1[] = {1, 3, 8, 12};
    int arr2[] = {2, 6, 7, 11};
    merge(arr1, arr2, 4, 4);
    print(arr1, 4);
    print(arr2, 4);
}