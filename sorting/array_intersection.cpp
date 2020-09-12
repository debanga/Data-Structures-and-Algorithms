// Intersection of two integer sorted arrays
// Distinct element is in output
#include <iostream>
#include <unordered_map>
using namespace std;

// O(m+n), S(n)
void find_intersection1(int arr1[], int arr2[], int m, int n) {
    int i {0}, j {0};
    unordered_map<int,int> umap;
    while(i<=m-1 && j<=n-1) {
        if (arr1[i]<=arr2[j]) {
            if (arr1[i] == arr2[j] && (umap[arr1[i]]==0)) {
                cout << arr1[i] << " ";
                umap[arr1[i]] = 1;
            }
            i++;
        }
        else {
            j++;
        }
    }
    /*
    if (i==m) {
        while (j<=n-1) {
            j++;
        }
    }
    if (j==n) {
        while (i<=m-1) {
            i++;
        }
    }
    */
    cout << endl;
}

// O(m+n), S(1)
void find_intersection2(int arr1[], int arr2[], int m, int n) {
    int i {0}, j {0};
    while(i<=m-1 && j<=n-1) {
        if (arr1[i]<=arr2[j]) {
            if (arr1[i] == arr2[j]) {
                if (i>0 && arr1[i]==arr1[i-1]) {
                    i++; 
                    continue;
                }
                cout << arr1[i] << " ";
            }
            i++;
        }
        else {
            j++;
        }
    }
    /*
    if (i==m) {
        while (j<=n-1) {
            j++;
        }
    }
    if (j==n) {
        while (i<=m-1) {
            i++;
        }
    }
    */
    cout << endl;
}

int main() {
    int arr1[] = {1, 1, 2, 3, 3, 5};
    int arr2[] = {1, 1, 2, 2, 3, 4, 5};
    find_intersection1(arr1, arr2, 6, 7);
    find_intersection2(arr1, arr2, 6, 7);
}
