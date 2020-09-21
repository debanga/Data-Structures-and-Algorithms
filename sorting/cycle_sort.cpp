// Cycle sort implementation
// O(N^2), mimimum memory write, in-place, not stable
#include <iostream>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// O(N^2)
void cycle_sort1(int arr[], int n) {
    for (int i=0; i<n-1; ++i) { // last element will be automatically sorted
        while (true) {
            int count {0};
            for (int j=0; j<n; ++j) {
                if (arr[j]<arr[i]) {
                    count++;
                }
            }
            if (count==i) { break;}
            else {
                // Dealing with duplicates
                if (arr[i]==arr[count]) {
                    count++;
                }

                // swap arr[i] and arr[count]
                int t = arr[count];
                arr[count] = arr[i];
                arr[i] = t;

                if (count==i) { break;} // dealing with duplicates (as 1 incement)
            }
        }
    }
}


int main() {
    int arr[] = {20, 40, 40, 50, 10, 30};
    cycle_sort1(arr, 6);
    print_array(arr, 6);
}



