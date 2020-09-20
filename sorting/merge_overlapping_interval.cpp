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


void print_array(vector<Interval> v) {
    for (int i=0; i<v.size(); ++i) {
        cout << "[" << v[i].start << "," << v[i].end << "] ";
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

    if (high.start <= low.end) {
        if (high.end<=low.end) {
            return {low.start, low.end};
        }
        else {
            return {low.start, high.end};
        }
    }
    else {
        return {-1, -1}; // not mergable
    } 
}

// Naive 
vector<Interval> merge_instervals(Interval arr[], int n) {
    bool index[n];
    fill_n(index, n, true);
    vector<Interval> v;

    for (int i=0; i<n; ++i) {
        if (index[i]) {
            cout << "==" << i << endl;
            Interval I = arr[i];
            for (int j=0; j<n; ++j) {
                if (i!=j) {
                    if (index[j]) {
                        cout << j << endl;
                        Interval t = to_merge(I, arr[j]);
                        if (t.start!=-1) {
                            cout << "--" << j << endl;
                            index[j] = false;
                            I = t;
                        }
                    }
                }
            }
            arr[i] = I;
        }
    }
    for (int i=0; i<n; ++i) {
        if (index[i]) {
            v.push_back(arr[i]);
        }
    }
    return v;
}

int main() {
    Interval arr[] = {{5,10}, {2,3}, {6,8}, {1,7}};
    
    //Interval I = to_merge({1,10}, {2,3});
    //cout << "[" << I.start << "," << I.end << "]" << endl;

    vector<Interval> v =merge_instervals(arr, 4);
    print_array(v);

}