#include <iostream>
using namespace std;

// Tortoise hare algorithm
int find_repeating(int arr[], int n) {
    // Phase 1
    int slow = arr[0]+1;
    int fast = arr[0]+1;
    do {
        slow = arr[slow]+1;
        fast = arr[arr[fast]+1]+1;
    }
    while (slow!=fast);

    // Phase 2
    slow = arr[0]+1;
    while (slow != fast ) {
        slow = arr[slow]+1;
        fast = arr[fast]+1;
    }

    return arr[slow-1];

}


int main() {
    int arr[] = {0, 1, 3, 4, 4, 2};
    int n = 6;

    cout << find_repeating(arr, n) << endl;
}


