// Union of two sorted arrays
// Should only contain distinct elements
#include <iostream>
using namespace std;

void array_union(int arr1[], int arr2[], int m, int n) {
    int i {0}, j {0};

    while (i<m && j<n) {
        //cout << "--" << i << ", " << j << "--" << endl;
        if (arr1[i] <= arr2[j]) {
            if (i>0 && arr1[i]==arr1[i-1]) {
                i++;
                continue;
            }
            cout << arr1[i] << " ";
            if (arr1[i]==arr2[j]) {++j;}
            i++;
        }
        else {
            if (j>0 && arr2[j]==arr2[j-1]) {
                j++;
                continue;
            }
            cout << arr2[j] << " ";
            j++;
        }
    }
    //cout << "--" << i << ", " << j << "--" << endl;
    if (i==m) {
        while (j<n) {
            if (j>0 && arr2[j]==arr2[j-1]) {
                j++;
                continue;
            }
            cout << arr2[j] << " ";
            j++;
        }
    }
    if (j==n) {
        while (i<m) {
            if (i>0 && arr1[i]==arr1[i-1]) {
                i++;
                continue;
            }
            cout << arr1[i] << " ";
            i++;
        }
    }

}

int main() {
    int arr1[] = {1, 1, 1, 2, 2, 4};
    int arr2[] = {1, 2, 3, 5};
    array_union(arr1, arr2, 6, 4);
}
#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> printIntersection(int arr1[], int arr2[], int N, int M)  {
    int i=0;
    int j=0;

    vector<int> v;
    int c = -1;
    int temp;

    while (i<=N-1 && j<= M-1) {
        if (arr1[i]<=arr2[j]) {
            if (arr1[i]==temp) 

            i++;
        }
        else {
            j++;
        }


    }



}

int main() {
    int arr[] = {1, 2, 3, 4};
    int brr[] = {2, 4, 6, 7, 8};

    vector<int> res;
    res = printIntersection(arr, brr, 4, 5);
    print_vector(res);

    return 0;
}