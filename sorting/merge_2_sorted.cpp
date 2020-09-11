#include <iostream>

using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// O(n*m), S(1)
void merge1(int arr1[], int arr2[], int m, int n) {
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

// O(m+n), S(m+n) if we store in a new array.
void merge2(int arr1[], int arr2[], int m, int n) {
    int i {0}, j {0};
    while(i<=m-1 || j<=n-1) {
        if (arr1[i]<arr2[j]) {
            cout<< arr1[i] << " ";
            ++i;
        }
        else {
            cout << arr2[j] << " ";
            ++j;
        }
    }
    if (i==m-1) {
        while(j<=n-1) { cout << arr2[j]; ++j;}
    }
    if (j==n-1) {
        while(i<=m-1) { cout << arr1[i]; ++i;}
    }
}

int main() {
    int arr1[] = {1, 3, 8, 12};
    int arr2[] = {2, 6, 7, 11};
    merge1(arr1, arr2, 4, 4);
    print(arr1, 4);
    print(arr2, 4);

    merge2(arr1, arr2, 4, 4);
}