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

bool compare(int x, int y) {
    float a = log2(x)/x;
    float b = log2(y)/y;
    if (a<b) {
        return true;
    }
    return false;
}

long long countPairs(int X[], int Y[], int m, int n) {
    sort(X, X+m, compare);
    sort(Y, Y+n, compare);

    int i = 0;
    int j = 0;

    int val = 0;
    int c = 0;
    while(i<=m-1 && j<=n-1) {
        float a = log2(X[i])/X[i];
        float b = log2(Y[j])/Y[j];
        if (a<=b) {
            i++;
            c += val;
        }
        else {
            j++;
            val++;
        }
    }
    while(i<=m-1) {
        i++;
        c += val;
    }

    return c;
}

int main() {
    int arr1[] = {2, 3, 4, 5};
    int arr2[] = {1, 2, 3};
    int M = 4;
    int N = 3;

    cout << countPairs(arr1, arr2, M, N) << endl;

}