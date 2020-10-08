#include <iostream>
using namespace std;

bool sum_exists(int arr[], int n, int x) {
    int left = 0;
    int right = n-1;

    while(left<right) {
        if (arr[left] + arr[right] == x) {
            return true;
        }
        else if (arr[left] + arr[right] < x) {
            left++;
        }
        else {
            right--;
        }   
    }
    return false;

}

int main() {
    int arr[] = {2, 5, 8, 12, 30};
    int n = 5;
    int x = 13;

    cout << sum_exists(arr, n, x) << endl;

}