#include <iostream>
#include <vector>
using namespace std;

typedef long long L;


// Function to find floor of x
// n: size of vector
// x: element whose floor is to find
int findFloor(vector<long long> v, long long n, long long x) {
    L l = 0;
    L r = n-1;
    L mid;
    L res = -1;
    
    while (l <= r) {
        mid = l + (r - l)/2;
        if (v[mid] == x) {
            return mid;
        }
        else if (v[mid] < x) {
            l = mid+1;
            res = mid;
        }
        else {
            r = mid-1;
        }
    }
    
    return res;
}


int main() {
    vector<L> v {2, 5, 7, 9};
    cout << findFloor(v, v.size(), 6) << endl;
}