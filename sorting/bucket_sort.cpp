// Bucket sort
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

// print array
void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// print vector
void print_vector(vector<int> v) {
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// find bucket id from a number
int find_bucket_id(int n, int max, int k) {
    int factor = (max+1)/k;
    return min(k-1, n/factor);
}

void insertion_sort(int arr[], int n) {

}

// bucket sort
void bucket_sort(int arr[], int n, int k) {
    // find max element in the array
    int max {0};
    for (int i=0; i<n; ++i) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }

    // assign buckets to the elements of the input array
    vector<vector<int>> buckets (k);
    for (int i=0; i<n; ++i) {
        int bid = find_bucket_id(arr[i], max, k);
        buckets[bid].emplace_back(arr[i]);
    }

    // sort buckets
    for (int i=0; i<k; ++i) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    // merge buckets
    int idx {0};
    for (int i=0; i<k; ++i) {
        for (int j=0; j<buckets[i].size(); ++j) {
            arr[idx] = buckets[i][j];
            idx++;
        }
    }
}

int main() {
    int arr[] = {20, 80, 40, 30, 70};
    int n = 5; // number of elements in the array
    int k = 4; // number of buckets

    bucket_sort(arr, n, k);
    print_array(arr, n);

    return 0;
}


