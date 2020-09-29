#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> v) {
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}


/*The function should return the modified array
as specified in the problem statement */
vector<int> threeWayPartition(vector<int> A, int a, int b)
{
    // Dutch National Flag algo.
    int N = A.size();
    int l {0}, i {0}, r {N-1};

    int c;
    while(r>=i) {
        if (A[i]<a) { c=0; }
        else if (A[i]<=b) { c=1; }
        else { c=2; }

        switch(c) {
            case 0:
                swap(A[i], A[l]);
                i++;
                l++;
                break;
            case 1:
                i++;
                break;
            case 2:
                swap(A[i], A[r]);
                r--;
                break;
        }
    }

    return A;
}

int main() {
    vector<int> A {76, 8, 75, 22, 59, 96, 30, 38, 36};
    int a = 44, b = 62;
    vector<int> res = threeWayPartition(A, a, b);
    print_vector(res);
}


