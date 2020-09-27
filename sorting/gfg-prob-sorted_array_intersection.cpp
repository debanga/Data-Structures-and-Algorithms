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

    int count = 0;
    while (i<=N-1 && j<= M-1) {
        if (arr1[i]<=arr2[j]) {
            if (count>0 && arr1[i]!=arr1[i-1]) {
                v.emplace_back(arr1[i]);
            }
            if (count==0) {
                v.emplace_back(arr1[i]);
            }
            i++;
            count++;
        }
        else {
            if (count>0 && arr2[j]!=arr2[j-1]) {
                v.emplace_back(arr2[j]);
            }
            if (count==0) {
                v.emplace_back(arr2[j]);
            }
            j++;
            count++;
        }
    }

    while (i<=N-1) {
        if (count>0 && arr1[i]!=arr1[i-1]) {
            v.emplace_back(arr1[i]);
        }
        if (count==0) {
                v.emplace_back(arr1[i]);
        }
        i++;
    }
    while (j<=M-1) {
        if (count>0 && arr2[j]!=arr2[j-1]) {
            v.emplace_back(arr2[j]);
        }
        if (count==0) {
                v.emplace_back(arr2[j]);
        }
        j++;
    }

    int res = 0;
    for (int i=1; i<v.size(); ++i) {
        if (v[i]==v[i-1]) {
            v[res] = v[i];
            res++;
        }
    }

    v.erase(v.begin()+res,v.end());

    if (v.size()!=0) {
        return v;
    }
    v.emplace_back(-1);
    return v;

}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4};
    int brr[] = {2, 2, 4, 4, 6, 7, 8};

    vector<int> res;
    res = printIntersection(arr, brr, 6, 7);
    print_vector(res);

    return 0;
}