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
    
    while(left<right) {
        mid = left + (right-left)/2;
        j = find_j(mid, n1, n2);
 
        if ((arr1[mid-1]<arr1[mid] && arr1[mid-1]<arr2[j]) && (arr2[j-1]<arr1[mid] && arr2[j-1]<arr2[j])) {
            if (is_odd) {
                return max(arr1[mid-1],arr2[j-1]);
            }
            else {
                cout << "[" << mid << "," << j << "]" << endl;
                return (max(arr1[mid-1],arr2[j-1])+min(arr1[mid],arr2[j]))/2.0;
            }
        }
        else if (arr2[j-1]>arr1[mid]) {
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }



}

int main() {
    int arr1[] = {10, 20, 30, 40, 50};
    int arr2[] = {5, 15, 25, 35, 45, 55, 65, 75, 85};
    int n1 = 5, n2 = 9;
    cout << find_median(arr1, arr2, n1, n2) << endl;

}