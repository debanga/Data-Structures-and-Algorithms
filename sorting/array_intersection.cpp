// Intersection of two integer sorted arrays
// Distinct element is in output
#include <iostream>
#include <unordered_map>
using namespace std;

void find_intersection(int arr1[], int arr2[], int m, int n) {
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


int main() {
    int arr1[] = {1, 1, 2, 3, 3, 5};
    int arr2[] = {1, 1, 2, 2, 3, 4, 5};
    find_intersection(arr1, arr2, 6, 7);
}
