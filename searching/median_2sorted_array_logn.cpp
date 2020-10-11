#include <iostream>
using namespace std;

int find_j(int i, int n1, int n2) {
    return (n1+n2+1)/2 - i;
}

float find_median(int arr1[], int arr2[], int n1, int n2) {
    int left = 0;
    int right = n1-1;
    int mid;
    int j;

    bool is_odd = false;
    if ((n1+n2)%2!=0) {
        is_odd = true;
    }
    
    while(left<right+2) {
        mid = left + (right-left)/2;
        j = find_j(mid, n1, n2);
 
        int L1 = mid==0 ? INT16_MIN : arr1[mid-1];
        int L2 = j==0 ? INT16_MIN : arr2[j-1];
        int R1 = mid==n1 ? INT16_MAX : arr1[mid];
        int R2 = j==n2 ? INT16_MAX : arr2[j];
        
        //cout << "[" << mid << "," << j << "]" << endl;
        //cout << "=[" << L1 << "," << L2 << "]" << endl;
        //cout << "==[" << R1 << "," << R2 << "]" << endl;

        if (max(L1, L2)<R1 && max(L1, L2)<R2) {
            if (is_odd) {
                return max(L1, L2);
            }
            else {
                return (max(L1, L2)+min(R1, R2))/2.0;
            }
        }
        else if (L2>R1) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    return -1;



}

int main() {
    /*
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {5, 15, 25, 35, 45, 55, 65, 75, 85};
    int n1 = 5, n2 = 9;
    cout << find_median(arr1, arr2, n1, n2) << endl;
    */
    
    int arr1[] = {10, 90};
    int arr2[] = {5, 15, 25, 35, 45, 55, 65, 75, 85};
    int n1 = 2, n2 = 9;
    cout << find_median(arr1, arr2, n1, n2) << endl;

}