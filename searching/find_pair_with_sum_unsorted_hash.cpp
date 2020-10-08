#include <iostream>
#include <unordered_map>
using namespace std;


bool is_present(int arr[], int n, int sum) {
    unordered_map<int, int> umap;
    for (int i=0; i<n; ++i) {
        umap[arr[i]]++;
    }
    for (int i=0; i<n; ++i) {
        if (umap[sum-arr[i]]>0) {
            if (sum-arr[i]==arr[i]) {
                if (umap[arr[i]]==1) {
                    continue;
                }
            }
            cout << "[" << arr[i] << "," << sum - arr[i] << "]" << endl;
            return true;
        }
    }
    return false;
}


int main() {
    // unsorted array
    int arr[] = {3, 5, 9, 2, 8, 10, 11};
    int n = 7;
    int sum = 15;

    cout << is_present(arr, n, sum) << endl;

}
