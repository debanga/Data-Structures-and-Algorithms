#include <iostream>
#include <algorithm>

using namespace std;

int findNumberOfTriangles(int arr[], int n) {
    int l, r;
    sort(arr, arr+n);
    int count {0};

    for (int i=n-1; i>=2; --i) {
        r = i-1;
        l = 0;

        while (l<r) {
            if (arr[l] + arr[r] > arr[i]) {
                count += r-l;
                r--;
            }
            else {
                l++;
            }
        }
    }

    return count;
}

int main() {
    int arr[] = {6, 4, 9, 7, 8};
    cout << findNumberOfTriangles(arr, 5) << endl;
}