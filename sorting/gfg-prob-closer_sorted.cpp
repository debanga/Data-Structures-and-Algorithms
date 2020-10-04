#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 0: left, 1: right
bool find_left_or_right(int arr[], int n, int idx, int x) {
    int p = 0;
    for (int i=idx-1; i<idx+2; ++i) {
        if ((arr[i]-x)>0) {
            p++;
        }
        else {
            p--;
        }
    }
    if (p>0) {
        return false;
    }
    else {
        return true;
    }
}

int search(int arr[], int n, int l, int r, int x) {
    int mid = l + (r-l)/2;
    
    if (arr[mid]==x) {
        return mid;
    }
    if (mid==0) {
        if (arr[mid+1]==x) {return mid+1;}
    }
    else if (mid==n-1) {
        if (arr[n-2]==x) {return n-2;}
    }
    else {
        for (int i=mid-1; i<mid+2; ++i) {
            if (arr[i]==x) {return i;}
        }
    }
    
    cout << "[" << l << "," << r << "] " << arr[mid] << endl;
    if (!find_left_or_right(arr, n, mid, x)) {
        if (mid-1>=l) {
            return search(arr, n, l, mid-1, x);
        }
    }
    else {
        if (mid+1<=r) {
            return search(arr, n, mid+1, r, x);
        }
    } 
    
    return -1;
}

int closer(int arr[],int n, int x)
{
    return search(arr, n, 0, n-1, x);
}

int main() {
    int arr[] = {83, 96, 139, 155, 243, 270, 276, 320, 339, 361, 380, 453, 555, 873, 867, 909, 911, 926, 940};
    int n = 19;
    int x = 155;
    cout << closer(arr, n, x) << endl;
    //cout << find_left_or_right(arr, n, 2, x) << endl;
}