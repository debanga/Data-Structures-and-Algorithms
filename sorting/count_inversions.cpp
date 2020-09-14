// Count inversions in an array
#include <iostream>
#include <vector>
using namespace std;

int count_merge(int arr[], int l, int m, int r) {
    int count {0};
    vector<int> L, R;
    
    //cout << l << " " << m << " " << r << " ";
    
    for (int i=l; i<m+1; ++i) {
        L.push_back(arr[i]);
    }
    
    for (int i=m+1; i<r+1; ++i) {
        R.push_back(arr[i]);
    }

    int a {0}, b {0};
    int inc {l};
    while (a<L.size() && b<R.size()) {
        if (L[a]<=R[b]) {
            arr[inc] = L[a];
            inc++;
            a++;
        }
        else {
            arr[inc] = R[b];
            count += L.size() - a;
            inc++;
            b++;
        }
    }
    while(a<L.size()) {
        arr[inc] = L[a];
        inc++;
        a++;
    }
    while(b<R.size()) {
        arr[inc] = R[b];
        inc++;
        b++;
    }
    
    return count;
}

int count_inversions(int arr[], int l, int r) {
    int count {0};

    if (l<r) {
        int m = l + (r-l)/2;
        count += count_inversions(arr, l, m); // left
        count += count_inversions(arr, m+1, r); // right
        count += count_merge(arr, l, m, r);
    }
    return count;
}

int main() { 
    int arr[] = {4, 6, 2, 3, 1};
    cout << count_inversions(arr, 0, 4) << endl;
}