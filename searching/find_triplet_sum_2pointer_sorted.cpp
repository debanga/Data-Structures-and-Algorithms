#include <iostream>
using namespace std;

bool is_triplet_sum(int arr[], int n, int x) {
    int l, r;

    for (int i=n-1; i>=0; --i) {
        l = 0;
        r = i-1;

        if (3*arr[i]<x) {
            break;
        }

        while(l<r) {
            if (arr[l]+arr[r]==x-arr[i]) {
                cout << "[" << arr[i] << "," << arr[l] << "," << arr[r] << "]" <<endl;
                return true;
            }
            else if (arr[l]+arr[r]>x-arr[i]) {
                r--;
            }
            else {
                l++;
            }
        }
    }

    return false;
}

int main() {
    int arr[] = {2, 3, 4, 8, 9, 20, 40};
    int n = 7;
    int x = 29;

    cout << is_triplet_sum(arr, n, x) << endl;

}