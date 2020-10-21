#include <iostream>
using namespace std;


// Find leftmost index of element X
int leftIndex(int N, int arr[], int X){
    int left = 0;
    int right = N-1;
    int mid;
    
    while (left<=right) {
        mid = left + (right - left)/2;
        
        if (arr[mid] == X) {
            if (mid == 0) {
                return 0;
            }
            else {
                if (arr[mid-1] != X) {
                    return mid;
                }
                else {
                    right = mid-1;
                }
            }
        }
        else if (arr[mid] < X) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return -1;
}


int main() {
    int arr[] = {10, 20, 20, 20, 20, 20, 20};
    int N = 7;
    int X = 20;

    cout << leftIndex(N, arr, X) << endl;
}
