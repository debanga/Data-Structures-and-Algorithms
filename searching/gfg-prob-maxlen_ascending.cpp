// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;


int maxStep(int A[], int N){
    int res = 0;
    int count = 0;
    
    for (int i=1; i<N; ++i) {
        if (A[i]>A[i-1]) {
            count++;
        }
        else {
            if (count > res) {
                res = count;
            }
            count = 0;
        }
    }
    if (count>res) {
        res = count;
    }
    
    return res;
}


int main() {
    int arr[] = {8, 5, 9, 8, 4};
    int N = 5;

    cout << maxStep(arr, N) << endl;

    return 0;
}
