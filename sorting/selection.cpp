// Selection sort
#include <iostream>
using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void selection(int arr[], int n) {
    for (int i=n; i>0; --i) {
        int max {0}, max_ind {0};
        for (int j=0; j<i; ++j) {
            if (arr[j]>=max) {
                max = arr[j];
                max_ind = j;
            }
        }
        int temp = arr[i-1];
        arr[i-1] = arr[max_ind];
        arr[max_ind] = temp;
        print(arr, 5);
    }
}

int main() {
    int arr[] = {4, 9, 2, 6, 1};
    selection(arr, 5);
    print(arr, 5);
}