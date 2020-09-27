#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    int i = 0;
    int j = 0;
    vector<int> v;
    
    int temp = -1;
    while(i<=n-1 && j<=m-1) {
        if (arr1[i]<=arr2[j]) {
            if (arr1[i]!=temp) {
                v.emplace_back(arr1[i]);
                temp = arr1[i];
            }
            i++;
        }
        else {
            if (arr2[j]!=temp) {
                v.emplace_back(arr2[j]);
                temp = arr2[j];
            }
            j++;
        }
    }
    while (i<=n-1) {
        if (arr1[i]!=temp) {
            v.emplace_back(arr1[i]);
            temp = arr1[i];
        }
        i++;
    }
    while (j<=m-1) {
        if (arr2[j]!=temp) {
            v.emplace_back(arr2[j]);
            temp = arr2[j];
        }
        j++;
    }

    return v;

}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int brr[] = {1, 2, 3};

    vector<int> res;
    res = findUnion(arr, brr, 5, 3);
    print_vector(res);

    return 0;
}