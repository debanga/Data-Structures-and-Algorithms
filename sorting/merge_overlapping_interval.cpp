// Merge overlapping intervals
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom interval structure
struct Interval {
    int start;
    int end; 
};

template <class T>
void print_array(T arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Check if two intervals are mergable or not
Interval to_merge(Interval a, Interval b) {
    Interval low;
    Interval high;
    
    if (a.start < b.start) {
        low = a;
        high = b;
    }
    else {
        low = b;
        high = a;
    }

    if (b.start <= a.end) {
        if (b.end<=a.end) {
            return {a.start, a.end};
        }
        else {
            return {a.start, b.end};
        }
    }
    else {
        return {-1, -1}; // not mergable
    } 
}

// Naive O(N^2), S(N)
void merge_instervals(Interval arr[], int n) {
    bool index[n];
    fill_n(index, n, true);
    for (int i=0; i<n; ++i) {
        if (index[i]) {
            bool flag = false;
            Interval I {arr[i]};
            index[i] = false;
            int count {0};
            for (int j=i+1; j<n; ++j) {
                if (index[j]) {
                    //cout << i << endl;
                    Interval temp;
                    temp = to_merge(I, arr[j]);
                    if (temp.start!=-1) {
                        I = temp;
                        flag = true;
                        count++;
                        index[j] = false;
                    }
                }
            }
            if (flag || count==0) {
                //print_array(index, n);
                cout << "[" << I.start << "," << I.end << "]" << endl;
            }
        }
    }
}

int main() {
    Interval arr[] = {{1,2}, {3,4}, {4,5}, {4,6}, {11, 14}};
    
    //Interval I = to_merge(arr[0], arr[1]);
    //cout << "[" << I.start << "," << I.end << "]" << endl;

    merge_instervals(arr, 5);

}