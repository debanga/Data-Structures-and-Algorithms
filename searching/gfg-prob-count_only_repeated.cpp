#include <iostream>
using namespace std;


int count_only_repeated(int arr[], int n) {
        // Find the repeating element 
    int l = 0;
    int r = n-1;
    int min = arr[0];
    int mid;
    int res = -1; // the repeating element
    
    while(l<=r) {
        mid = l + (r-l)/2;
        if (arr[mid]==min+mid) {
            l = mid+1;
        }
        else if(arr[mid]< min+mid) {
            r = mid-1;
            res = arr[mid];
        }    
    }

    int up;
    int low;
    if (arr[n-1] == res) {
        up = n;
    }
    else { // find up

    }

    if (arr[0] == res) {
        low = -1;
    }
    else { // find low

    }



}


int main() {
    int arr[] = {1, 2, 2, 3};
    int n = 4;
    cout << count_only_repeated(arr, n) << endl;
}
