#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find first smallest positive
// missing number in the array
int missingNumber(int arr[], int n) { 
    // Update
    int count_pos = 0;
    for (int i=0; i<n; ++i) {
        if (arr[i]>0) {
            arr[count_pos]=arr[i];
            count_pos++;
        }
    }
    print(arr, count_pos);

    for(int i=0; i<count_pos; i++) {
	    if(abs(arr[i]) - 1 < count_pos && arr[ abs(arr[i]) - 1] > 0) 
	    arr[ abs(arr[i]) - 1] = -arr[ abs(arr[i]) - 1]; 
    } 

    print(arr, count_pos); 

    for (int i=0; i<count_pos; i++) {
        if (arr[i]>0) {
            return i+1;
        }
    } 
    return count_pos+1;


} 

int main() {
    int arr[] = {1,2,3};
    int n = 3;

    cout << missingNumber(arr, n) << endl;


}