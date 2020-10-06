#include <iostream>
#include <cmath>
using namespace std;


int find_sqroot(int x) {
    int ans = -1;
    int l = 0;
    int r = x;
    int mid;

    while(l<=r) {
        mid = l + (r-l)/2;

        if (mid*mid == x) {
            return mid;
        }

        if (mid*mid < x) {
            ans = mid;
            l = mid+1;
        }
        else if (mid*mid > x) {
            r = mid-1;
        }
    }
    return ans;

}


int main() {
    int x = 21;
    cout << find_sqroot(x) << endl;
}