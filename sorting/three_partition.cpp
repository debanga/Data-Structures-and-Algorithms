// You need to segregate an array of elements containing three types of elements. The types are:
// Sort an array of 0s, 1s, 2s.
// Three-way partitioning when multiple occurrences of a pivot may exist.
// Partitioning around a range.

#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}   

// Naive
void three_partition(int arr[], int n, int rl, int rh) { //@buggy
    int i {-1}, j {n};
    while (true) {
        do {
            i++;
        }
        while (arr[i]<rl-0.5);
        do {
            j--;
        }
        while(arr[j]>rl-0.5);
        if (i>=j) {break;}
        // swap
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;   
    }

    i = -1;
    j = n;
    while (true) {
        do {
            i++;
        }
        while (arr[i]<rh+0.5);
        do {
            j--;
        }
        while(arr[j]>rh+0.5);
        if (i>=j) {break;}
        // swap
        int t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;   
    }   

}

// swap
void swap(int& a, int &b) {
    int t = a;
    a = b;
    b = t;
}

// Dutch National Flag
void dutch_flag(int arr[], int n, int rl, int rh) {
    // Define 3 pointer
    int l = 0;
    int m = 0;
    int h = n-1;

    010

    // 0000 (l) 1111 0 (m) xxxx (h) 2222
    while (m<=h) {
        int c {0};

        if (arr[m]<rl) { c=0; }
        else if (arr[m]<rh+1) { c=1; }
        else { c=2; }

        switch (c) {
            case 0: 
                // swap (l,m)
                swap(arr[l], arr[m]);
                l++;
                m++;
                break;
            case 1:
                m++;
                break;
            case 2:
                // swap (h,m)
                swap(arr[h], arr[m]);
                h--;
                break;
        }
    }
}




int main() {
    int arr[] = {2, 10, 2, 12, 10, 20, 10, 30};

    dutch_flag(arr, 8, 10, 11);
    print_array(arr, 8);


}