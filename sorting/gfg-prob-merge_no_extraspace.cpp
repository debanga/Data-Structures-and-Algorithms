#include <iostream>
#include <algorithm>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// O(n*m*log(m)) 
void merge0(int arr1[], int arr2[], int n, int m) 
{ 

    int j = 0;
    for (int i=0; i<n; ++i) {
        if (arr1[i] > arr2[j]) {
            // swap
            int t = arr2[j];
            arr2[j] = arr1[i];
            arr1[i] = t;

            // sort array2
            sort(arr2,arr2+m);
        }
    }
    
} 

// O(n*m 
void merge1(int arr1[], int arr2[], int n, int m) 
{ 

    int p = 0;
    for (int i=0; i<n; ++i) {
        if (arr1[i] > arr2[p]) {
            // swap
            int t = arr2[p];
            arr2[p] = arr1[i];
            arr1[i] = t;

            // sort array2
            bool flag = false;
            int temp = arr2[p];
            for (int j=1; j<m; ++j) {
                if (arr2[j]<temp) {
                    arr2[j-1] = arr2[j];
                }
                if (arr2[j]>=temp) {
                    arr2[j-1] = temp;
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                arr2[m-1] = temp;
            }
        }
    }
    
} 

int get_val(int arr1[], int arr2[], int n, int m, int i) {
    if (i<n) {
        return arr1[i];
    }
    else {
        return arr2[i-n];
    }
}

int set_val(int arr1[], int arr2[], int n, int m, int i, int val) {
    if (i<n) {
        arr1[i] = val;
    }
    else {
        arr2[i-n] = val;
    }
}

// O((n+m)*log(n+m)): @todo: comb sort
void merge2(int arr1[], int arr2[], int n, int m) 
{ 
    int p = (m + n)/2;

    int count = 0;
    while (true) {
        bool is_swap = false;
        for (int i=0; i<m+n-p; ++i) {
            if (get_val(arr1, arr2, n, m, i)>get_val(arr1, arr2, n, m, i+p)) {
                int t = get_val(arr1, arr2, n, m, i);
                set_val(arr1, arr2, n, m, i, get_val(arr1, arr2, n, m, i+p));
                set_val(arr1, arr2, n, m, i+p, t);
                is_swap = true;
            }
        }
        p = p / 2;
        if (p<1) { p = 1; }
        if (p==1 && !is_swap) {
            break;
        }
        count++;
    }
    cout << count << endl;

} 

int main() {
    int arr1[] = {1, 3, 6, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = 4;
    int m = 5;

    merge2(arr1, arr2, n, m);
    print_array(arr1, n);
    print_array(arr2, m);
}