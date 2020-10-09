#include <iostream>
using namespace std;

float find_median(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    int idx = (n+m+1)/2-1;
    int is_odd = false;
    if ((n+m)%2==1) {
        is_odd = true;
    }
    int a, b;

    int count = 0;
    while(i<n && j<n) {
        if (arr1[i]<=arr2[j]) {
            if (count==idx) { a = arr1[i]; }
            if (count==idx+1) { b = arr1[i]; }
            count++;
            i++;
        }
        else {
            if (count==idx) { a = arr2[j]; }
            if (count==idx+1) { b = arr2[j]; }
            count++;
            j++;
        }
    }
    while(i<n) {  
        if (count==idx) { a = arr1[i]; }
        if (count==idx+1) { b = arr1[i]; }
        count++;
        i++; 
    }
    while(j<n) {
        if (count==idx) { a = arr2[j]; }
        if (count==idx+1) { b = arr2[j]; }
        count++; 
        j++; 
    }
    
    if (is_odd) {
        return a;
    }
    else {
        return (a+b)/2.0;
    }

}

int main() {
    int arr1[] = {1, 2, 3, 4, 5, 6};
    int arr2[] = {10, 20, 30, 40, 50};
    int n = 6;
    int m = 5;

    cout << find_median(arr1, arr2, n, m) << endl;
}
