#include <iostream>
using namespace std;

int algo1(int arr[], int n, int sum) {
    int l = 0;
    int r = n-1;
    while (l<r) {
        if (arr[r]+arr[l]==sum) {
            cout << "[" << arr[l] << "," << arr[r] << "]" << endl;
            return true;
        }
        else if (arr[r]+arr[l]>sum) {
            r--;
        }
        else if (arr[r]+arr[l]<sum) {
            l++;
        }
    }
    return false;
}


int main() {
    int arr[] = {1, 3, 5, 8, 12, 15};
    int n = 6;
    int sum = 9;

    cout << algo1(arr, n, sum) << endl;


}
