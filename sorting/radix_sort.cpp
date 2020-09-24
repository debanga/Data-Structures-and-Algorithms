// Radix sort
#include <iostream>
#include <cmath>
using namespace std;

void print_array(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Find the digits in the maximum number in the array
int find_max_num_bits(int arr[], int n) {
    int max {0};
    for (int i=0; i<n; ++i) {
        double p = log10(arr[i]+1);
        int c {int(ceil(p))};
        if (c > max) {
            max = c;
        }
    }
    return max;
}

// Find the value of kth digit (first from right has k=1)
int find_kth_digit(int num, int k) {
    double p = double(num)/pow(10,k-1);
    int q = int(floor(p));
    return q % 10;
}

// Counting sort considering the kth digit of the array elements
void counting_sort(int arr[], int n, int k) {
    int count[10];
    // initialize count array
    for (int i=0; i<10; ++i) {
        count[i] = 0;
    }
    
    // fill up counts
    for (int i=0; i<n; ++i) {
        int d = find_kth_digit(arr[i], k);
        count[d]++;
    }
      
    // integrate counts
    for (int i=1; i<10; ++i) {
        count[i] = count[i] + count[i-1]; 
    }
    
    int out[n];
    // traverse number array and update final output
    for (int i=n-1; i>=0; --i) {
        int d = find_kth_digit(arr[i], k); 
        out[count[d]-1] = arr[i];
        count[d]--;
    }

    // fill up original array with output
    for (int i=0; i<n; ++i) {
        arr[i] = out[i];
    }

}

void radix_sort(int arr[], int n) {
    // find maximum bit
    int D = find_max_num_bits(arr, n);

    // run a loop over each digit
    for (int i=0; i<D; ++i) {
        counting_sort(arr, n, i+1);
    }
}

int main() {
    int arr[] = {315, 212, 6, 8, 100, 500};
    int n {6};

    // perform radix sort
    radix_sort(arr, n);
    print_array(arr, n);

    return 0;
}