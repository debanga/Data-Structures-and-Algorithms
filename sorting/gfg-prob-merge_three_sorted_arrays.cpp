#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
    for (auto& val : v) {
        cout << val << " ";
    }
    cout << endl;
}


int get_val(vector<int> A, vector<int> B, int idx) {
    if (idx<A.size()) {
        return A[idx];
    }
    else {
        return B[idx - A.size()];
    }
}

// Function to merge three sorted arrays
// A, B, and C: input sorted arrays
vector<int> mergeThree(vector<int>& A, vector<int>& B, vector<int>& C) 
{ 
    vector<int> res;

    // Merge A,B and put in a new vector
    int i = 0;
    int j = 0;
    while (i<A.size() && j<B.size()) {
        if (A[i]<=B[j]) {
            res.emplace_back(A[i]);
            i++;
        }
        else {
            res.emplace_back(B[j]);
            j++;
        }
    }
    while (i<A.size()) {
        res.emplace_back(A[i]);
        i++;
    }
    while (j<B.size()) {
        res.emplace_back(B[j]);
        j++;
    }

    // copy back
    for (int i=0; i<res.size(); ++i) {
        if (i<A.size()) {
            A[i] = res[i];
        }
        else {
            B[i-A.size()] = res[i];
        }
    }

    //
    i = 0;
    j = 0;
    int N = res.size();
    res.clear();
    while (i<N && j<C.size()) {
        if (get_val(A,B,i)<=C[j]) {
            res.emplace_back(get_val(A,B,i));
            i++;
        }
        else {
            res.emplace_back(C[j]);
            j++;
        }
    }
    while (i<N) {
        res.emplace_back(get_val(A,B,i));
        i++;
    }
    while (j<C.size()) {
        res.emplace_back(C[j]);
        j++;
    }

    return res;

} 

int main() {
    vector<int> A = {1,2};
    vector<int> B = {2,3,4};
    vector<int> C = {4,5,6,7};
    vector<int> res = mergeThree(A,B,C);
    print_vector(res);
    
}
