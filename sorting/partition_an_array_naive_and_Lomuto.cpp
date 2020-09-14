// Create partison from an array
#include <iostream>
#include <vector>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Naive: O(n), S(n)
void create_partition1(int arr[], int pivot, int n) {
    vector<int> t;
    for (int i=0; i<n; ++i) {
        if (i!=pivot && arr[i]<=arr[pivot]) {
            t.push_back(arr[i]);
        }
    }
    t.push_back(arr[pivot]);
    for (int i=0; i<n; ++i) {
        if (i!=pivot && arr[i]>arr[pivot]) {
            t.push_back(arr[i]);
        }
    }   
    for (int i=0; i<n; ++i) {
        arr[i] = t[i];
    }
}

// test
void create_partition2(int arr[], int p, int n) {
    int i {0}, j {n-1};

    while (i<j) {
        if (arr[i]<=p) {
            i++;
        }
        else {
            //swap
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            j--;
        }
    }
}

// Lomuto partition
void create_partition3(int arr[], int n) {
    int l {-1};
    int pivot {arr[n-1]};

    for (int i=0; i<n-1; ++i) {
        if (arr[i]<pivot) {
            l++;
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
    int temp = arr[l+1];
    arr[l+1] = arr[n-1];
    arr[n-1] = temp;
}

// Lomuto partition with generalized pivot: O(n), S(1)
void create_partition4(int arr[], int n, int p) {
    int l {-1};

    // swap p with last element
    int temp = arr[p];
    arr[p] = arr[n-1];
    arr[n-1] = temp;

    int pivot {arr[n-1]};

    for (int i=0; i<n-1; ++i) {
        if (arr[i]<pivot) {
            l++;
            int temp = arr[l];
            arr[l] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[l+1];
    arr[l+1] = arr[n-1];
    arr[n-1] = temp;
}

int main() {
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int p = 6;
    //create_partition1(arr, p, 7);
    //create_partition2(arr, p, 7);
    //create_partition3(arr, 7);
    create_partition4(arr, 7, 4);
    print_array(arr, 7);

    // corner case
    int arr1[] = {70, 60, 80, 40, 30};
    create_partition3(arr1, 5);
    print_array(arr1, 5);
 
    int arr2[] = {30, 40, 20, 50, 80};
    create_partition3(arr2, 5);
    print_array(arr2, 5);

}
