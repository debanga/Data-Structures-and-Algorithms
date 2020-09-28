#include <iostream>
#include <algorithm>
using namespace std;

/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
bool findZeroTriplets(int arr[], int n)
{
    sort(arr, arr+n);

    int l, r;
    for (int i=0; i<n-2; i++) {
        l = i+1;
        r = n-1;

        while(l<r) {
            if (arr[i] + arr[l] + arr[r] == 0) {
                cout << "[" << arr[i] << "," << arr[l] << "," << arr[r] << "]" << endl;
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    return false;
}

bool findGivenSumTriplets(int arr[], int n, int sum)
{
    sort(arr, arr+n);

    int l, r;
    for (int i=0; i<n-2; i++) {
        l = i+1;
        r = n-1;

        while(l<r) {
            if (arr[i] + arr[l] + arr[r] == sum) {
                cout << "[" << arr[i] << "," << arr[l] << "," << arr[r] << "]" << endl;
                return true;
            }
            else if (arr[i] + arr[l] + arr[r] < sum) {
                l++;
            }
            else {
                r--;
            }
        }
    }
    return false;
}

int main() {
    int arr[] = {-1, -92, -64, 60, 93, 8};
    cout << findZeroTriplets(arr, 6) << endl;
    cout << findGivenSumTriplets(arr, 6, 4) << endl;
}