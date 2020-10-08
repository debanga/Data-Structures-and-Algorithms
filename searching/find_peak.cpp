#include <iostream>
using namespace std;


int find_peak(int arr[], int n) {
    if (n==1) {
        return 0;
    }
    if (arr[0]>=arr[1]) {
        return 0;
    }
    if (arr[n-1]>=arr[n-2]) {
        return n-1;
    }

    int left = 0;
    int right = n-1;
    int mid;



}


int main() {
    int arr[] = {5, 10, 20, 15, 7};
    cout << 1 << endl;
}