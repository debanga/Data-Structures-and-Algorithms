// Merge sort
#include <iostream>
#include <vector>
using namespace std;

// Print array
void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_part(int arr[], int m, int n) {
    for (int i=m; i<=n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_vector(vector<int> v) {
    for (int i=0; i<v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int arr[], int l, int m, int r) {
    vector<int> left, right;
    for (int i=l; i<=m; ++i) {
        left.push_back(arr[i]);
    }
    
    for (int i=m+1; i<=r; ++i) {
        right.push_back(arr[i]);
    }
    print_vector(left);
    print_vector(right);

    int a {0}, b {0};
    int count {l};
    while(a<left.size() && b<right.size()) {
        if (left[a]<=right[b]) {
            cout << "L ";
            arr[count] = left[a];
            a++;
            count++;
        }
        else {
            cout << "R ";
            arr[count] = right[b];
            b++;
            count++;
        }
    }
    if (a==left.size()) {
        cout << "R+ ";
        while(b<right.size()) {
            arr[count] = right[b];
            b++;
            count++;
        }
    }
    if (b==right.size()) {
        cout << "L+ ";
        while(a<left.size()) {
            arr[count] = left[a];
            a++;
            count++;
        }
    }
}

void mergesort(int arr[], int l, int r) {
    if (l<r) {
        int m = l + (r-l)/2; // prevent overflow
        mergesort(arr, l, m);
        mergesort(arr, m+1, r);
        cout << "Before: ";
        print_part(arr, l, r);
        merge(arr, l, m, r);
        cout << "After: ";
        print_part(arr, l, r);
    }
}

int main() {
    int arr[] = {3, 1, 4, 4, 2, 9};
    mergesort(arr, 0, 5);
    //print(arr, 6);
}