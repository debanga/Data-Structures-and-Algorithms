#include <iostream>
#include <algorithm>
using namespace std;

int findPlatform(int arr[], int dep[], int n)
{
    sort(arr, arr+n);
    sort(dep, dep+n);

    int i = 0;
    int j = 0;
    int plat = 0;
    int max = 0;
    while(i<=n-1 && j<=n-1) {
        if (arr[i]<=dep[j]) {
            i++;
            plat++;
            if (plat>max) {
                max = plat;
            }
        }
        else {
            j++;
            plat--;
        }
    }
    while (i<=n-1) {
        i++;
        plat++;
        if (plat>max) {
            max = plat;
        }
    }
    while (j<=n-1) {
        j++;
        plat--;
    }

    return max;
}

int main() {
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    int n = 6;
    cout << findPlatform(arr, dep, n) << endl;

}