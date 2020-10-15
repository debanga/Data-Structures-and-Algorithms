#include <iostream>
using namespace std;

int find_majority(int arr[], int n) {
    // Phase 1: find a majority candidate
    int res = arr[0];
    int count = 1;

    for (int i=0; i<n; ++i) {
        if (arr[i]==res) {
            count++;
        }

        if (count==0) {
            res = i; 
            count = 1;
        }
    }
    cout << "Candidate: " << res << endl; 

    // Phase 2: check the validity of the candidate
    count = 0;
    for (int i=0; i<n; ++i) {
        if (arr[i] == arr[res]) {
            count++;
        }
    }

    if (count > n/2) {
        return arr[res];
    }
    
    return -1;
}


int main() {
    int arr[] = {1, 2, 2, 3, 2, 2, 3};
    int n = 7;

    cout << find_majority(arr, n) << endl;
}