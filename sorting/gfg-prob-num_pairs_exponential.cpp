 /*
 Given two arrays X and Y of positive integers, 
 find the number of pairs such that xy > yx 
 (raised to power of) where x is an element 
 from X and y is an element from Y.
 */

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge(int arr1[], int arr2[], int M, int N) {


    for (int i=0; i<M; ++i) {
        arr1[i] = 100000*log(arr1[i])/arr1[i];
    }
    for (int i=0; i<N; ++i) {
        arr2[i] = 100000*log(arr2[i])/arr2[i];
    }

    sort(arr1, arr1+M);
    sort(arr2, arr2+N);
    print_array(arr1, M);
    print_array(arr2, N);

    int i = 0;
    int j = 0;

    int val = 0;
    int c = 0;
    while(i<=M-1 && j<=N-1) {
        if (arr1[i]<=arr2[j]) {
            i++;
            if (i>0) {
                if (arr1[i]!=arr1[i-1]) {
                    c += val;
                }
            }
        }
        else {
            j++;
            if (j>0) {
                if (arr2[j]!=arr2[j-1]) {
                    val++;
                }
            }
        }
    }
    while(i<=M-1) {
        i++;
        c += val;
    }

    return c;
}

int main() {
    int arr1[] = {2, 1, 6};
    int arr2[] = {1, 5};
    int M = 3;
    int N = 2;

    cout << merge(arr1, arr2, M, N) << endl;

}