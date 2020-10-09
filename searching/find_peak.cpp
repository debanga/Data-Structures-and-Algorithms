#include <iostream>
using namespace std;


int find_peak(int arr[], int n) {
    if (n==1) {
        return arr[0];
    }
    if (arr[0]>=arr[1]) {
        return arr[0];
    }
    if (arr[n-1]>=arr[n-2]) {
        return arr[n-1];
    }

    int left = 0;
    int right = n-1;
    int mid;

    while (left<=right) {
        mid = left + (right-left) / 2;

        if (arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1]) {
            return arr[mid];
        }
        else if (arr[mid-1]>=arr[mid]) {
            right = mid-1;
        }
        else if (arr[mid+1]>=arr[mid]) {
            left = mid+1;
        }
    }
}


int main() {
    int arr[] = {5, 10, 20, 15, 7};
    int n = 5;
    cout << find_peak(arr, n) << endl;

    int arr1[] = {10, 11, 15, 5, 23, 90, 67};
    int n1 = 7;
    cout << find_peak(arr1, n1) << endl;

    int arr2[] = {80, 70, 40};
    int n2 = 3;
    cout << find_peak(arr2, n2) << endl;

}