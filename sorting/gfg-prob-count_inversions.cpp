#include <iostream>
#include <vector>
using namespace std;

void print_array(int arr[], int low, int high) {
    for (int i=low; i<=high; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int merge(int arr[], int low, int mid, int high) {
    cout << "==" << endl;
    cout << "Before: ";
    print_array(arr, low, high);

    int temp[high-low+1];

    int i = low;
    int j = mid+1;

    int idx = 0;
    int count = 0;
    int acc = 0;
    while (i<=mid && j<=high) {
        if (arr[i]<=arr[j]) {
            temp[idx++] = arr[i];
            acc += count;
            i++;
        }
        else {
            count++;
            temp[idx++] = arr[j];
            j++;
        }
    }
    while (i<=mid) {
        temp[idx++] = arr[i];
        acc += count;
        i++;
    }
    while (j<=high) {
        temp[idx++] = arr[j];
        j++;
    }

    for (int i=low; i<=high; ++i) {
        arr[i] = temp[i-low];
    }

    cout << "After: ";
    print_array(arr, low, high);

    return acc;
}

int merge_sort(int arr[], int low, int high) {
    int mid = low + (high-low)/2;

    int count {0};
    if (low<high) {
        count += merge_sort(arr, low, mid);
        count += merge_sort(arr, mid+1, high);
        count += merge(arr, low, mid, high);
    }

    return count;
}

int main() {
    int arr[] = {2,4,1,3,5};
    int n = 5;
    //cout << merge(arr, 0, 2, 5);
    cout << merge_sort(arr, 0, n-1) << endl;
}