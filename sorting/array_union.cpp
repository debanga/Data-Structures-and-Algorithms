// Union of two sorted arrays
// Should only contain distinct elements
#include <iostream>
using namespace std;

void array_union(int arr1[], int arr2[], int m, int n) {
    int i {0}, j {0};

    while (i<m && j<n) {
        //cout << "--" << i << ", " << j << "--" << endl;
        if (arr1[i] <= arr2[j]) {
            if (i>0 && arr1[i]==arr1[i-1]) {
                i++;
                continue;
            }
            cout << arr1[i] << " ";
            if (arr1[i]==arr2[j]) {++j;}
            i++;
        }
        else {
            if (j>0 && arr2[j]==arr2[j-1]) {
                j++;
                continue;
            }
            cout << arr2[j] << " ";
            j++;
        }
    }
    //cout << "--" << i << ", " << j << "--" << endl;
    if (i==m) {
        while (j<n) {
            if (j>0 && arr2[j]==arr2[j-1]) {
                j++;
                continue;
            }
            cout << arr2[j] << " ";
            j++;
        }
    }
    if (j==n) {
        while (i<m) {
            if (i>0 && arr1[i]==arr1[i-1]) {
                i++;
                continue;
            }
            cout << arr1[i] << " ";
            i++;
        }
    }

}

int main() {
    int arr1[] = {1, 1, 1, 2, 2, 4};
    int arr2[] = {1, 2, 3, 5};
    array_union(arr1, arr2, 6, 4);
}
