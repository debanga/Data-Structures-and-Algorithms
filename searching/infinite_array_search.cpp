#include <iostream>
using namespace std;

int binary_search(int arr[], int l, int r, int x) {
    int left = l;
    int right = r;
    int mid;

    while(left<=right) {
        mid = left + (right-left)/2;
        if (arr[mid]==x) {
            return mid;
        }
        else if (arr[mid]<x) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return -1;
}

int find_index(int arr[], int x) {
    if (arr[0]==x) {return 0;}
    int c = 1;
    int max;
    while (true) {
        if (arr[c]>x) {
            max = c;
            break;
        }
        if (arr[c]==x) {
            return c;
        }
        c = c*2;
    }
    return binary_search(arr, c/2 + 1 , c-1, x);
}


int main() {
    int N = 1000000;
    int arr[N];
    for (int i=0; i<N; ++i) {
        arr[i] = 2*i;
    }

    int x = 100;
    cout << find_index(arr, x) << endl;
}