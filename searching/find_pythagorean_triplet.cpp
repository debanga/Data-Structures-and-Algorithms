#include <iostream>
using namespace std;

bool is_pyth_triplet(int arr[], int n) {
    int l, r;
    int c2;

    for (int i=n-1; i>=2; --i) {
        l = 0;
        r = i-1;
        c2 = arr[i]*arr[i];

        if (2*arr[r]*arr[r]<c2) {
            continue;
        }
    
        while (l<r) {
            if ((arr[l]*arr[l] + arr[r]*arr[r]) == c2) {
                cout << "[" << arr[l] << "," << arr[r] << "," << arr[i]<< "]" << endl;
                return true;
            }
            else if ((arr[l]*arr[l] + arr[r]*arr[r]) > c2 ) {
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
    int arr[] = {2, 3, 4, 6, 60, 91, 93, 109};
    int n = 8;
    cout << is_pyth_triplet(arr, n) << endl;
    
}