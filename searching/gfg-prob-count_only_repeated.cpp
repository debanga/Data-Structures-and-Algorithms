#include <iostream>
using namespace std;

int binary_search(int arr[], int n, int k) {
    int l = 0;
    int r = n-1;
    int mid;
    
    while(l<=r) {
        mid = l + (r-l)/2;
        
        if (arr[mid] == k) {
            return mid;
        }
        else if (arr[mid]<k) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    
    return -1;
}


pair<int, int> count_only_repeated(int arr[], int n) {
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
        up = binary_search(arr, n, res+1);
    }

    if (arr[0] == res) {
        low = -1;
    }
    else { // find low
        low = binary_search(arr, n, res-1);
    }

    pair<int, int> p {res, up - low - 1};
    return p;
}


int main() {
    int arr[] = {1, 2, 3, 3};
    int n = 4;
    pair<int, int> p = count_only_repeated(arr, n);
    cout << p.first << " " << p.second << endl;
}
