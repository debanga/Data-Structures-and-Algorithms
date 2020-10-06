#include <iostream>
#include <cmath>
using namespace std;


int find_sqroot(int x) {
    if (x<0) { return -1;}
    int l = 0;
    int r = x;
    int mid;

    while(l<=r) {
        mid = l + (r-l)/2;

        if (mid*mid == x) {
            return mid;
        }

        if (mid*mid < x) {
            l = mid+1;
        }
        else if (mid*mid > x) {
            r = mid-1;
        }
    }
    return min(l,r);

}


int main() {
    int x = -10;
    cout << find_sqroot(x) << endl;
}