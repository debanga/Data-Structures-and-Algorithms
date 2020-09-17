// Ref: geeks4geeks 
// find a combination of m elements such that (max-min) is minimum for all the elements
#include <iostream>
#include <algorithm>
using namespace std;

// Naive
int chocolate1(int arr[], int m, int size) {
    // base
    if (m > size) { return -1;}

    // sort
    sort(arr, arr+size);

    //slide a window of width m to find where we satisfy the asked constraint
    int min {arr[m-1]-arr[0]}, min_ind {0};
    for (int i=1; i<size-m+1; ++i) {
        int v = arr[i+m-1]-arr[i];
        if (v < min) {
            min = v;
            min_ind = i;
        }
    }

    return min;
}

int main() {
    int arr1[] {7, 3, 2, 4, 9, 12, 56}, m1 {3};
    int arr2[] {3, 4, 1, 9, 56, 7, 9, 12}, m2 {5};

    cout << chocolate1(arr1, m1, 7) << endl;
    cout << chocolate1(arr2, m2, 8) << endl;

}