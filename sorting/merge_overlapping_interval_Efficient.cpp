#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct Interval {
    int start;
    int end;
};


Interval merge(Interval a, Interval b) {
    Interval low, high;
    if (a.start<=b.start) {
        low = a;
        high = b;
    }
    else {
        low = b;
        high = a;
    }

    if (high.start<=low.end) {
        if (high.end>low.end){
            return {low.start, high.end};
        }
        else {
            return {low.start, low.end};
        }
    }
    else {
        return {-1,-1};
    }
}


void print_interval_array(Interval arr[], int n) {
    for (int i=0; i<n; ++i) {
        cout << "[" << arr[i].start << " " << arr[i].end << "] ";
    }
    cout << endl;
}


bool interval_compare (Interval a, Interval b) {
    if (a.start <= b.start) {
        return true;
    }
    return false;
}

// O(N), S(N)
void merge_intervals(Interval arr[], int n) {
    vector<Interval> v;
    v.emplace_back(arr[0]);

    for (int i=1; i<n; ++i) {
        Interval I = merge(arr[i], v.back());
        if (I.start!=-1) {
            v.back() = I;
        }
        else {
            v.emplace_back(arr[i]);
        }
    }
    // print final array
    for (int i=0; i<v.size(); ++i) {
        cout << "[" << v[i].start  << "," << v[i].end << "] " << " ";
    }
}

// O(N), S(1)
void merge_intervals_better(Interval arr[], int n) {
    int res {0};

    for (int i=1; i<n; ++i) {
        Interval I = merge(arr[res], arr[i]);
        if (I.start!=-1) {
            arr[res] = I;
        }
        else {
            ++res;
            arr[res] = arr[i];
        }
    }
    // print final array
    for (int i=0; i<=res; ++i) {
        cout << "[" << arr[i].start  << "," << arr[i].end << "] " << " ";
    }
}


int main() {
    Interval arr[] = {{5,10}, {2,3}, {6,8}, {1,7}, {11,12}};
    int n = 5;

    // test sorting by first element
    sort(arr, arr+n, interval_compare);
    //merge_intervals(arr, n);
    merge_intervals_better(arr, n);

}

