// Count max intersection
// Also, party max meeting problem
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


// Convert sample array id into time format => HHMM
int id_to_time(int id) {
    return floor(id/60) + (id%60);
}


// Find if a sample is in a time interval
int sample_in_interval(int arr[], int dep[], int interval_id, int sample_id) {
    // convert sample id to time
    int t = id_to_time(sample_id);

    // check if the time t is in the interval
    if (t>=arr[interval_id] && t<= dep[interval_id]) {
        return 1;
    }
    else {
        return 0;
    }
}


// Naive O(1440N), S(1)
int count_max_intersection(int arr[], int dep[], int n) {
    int N {1440}; // total samples for every minutes in a 24 hour duration
    int max {0};

    for (int i=0; i<N; ++i) {
        int count {0};
        for (int j=0; j<n; ++j) {
            count += sample_in_interval(arr, dep, j, i);
        }
        if (count > max) {
            max = count;
        }
    }

    return max;
}

// O(NlogN), S(1) in a merge sort style
int count_max_intersection2(int arr[], int dep[], int n) {
    sort(arr, arr+n);
    sort(dep, dep+n);

    int i {0}, j {0};
    int count {0};
    int max {0};

    while(i<n || j<n) {
        if (arr[i]<=dep[j]) {
            i++;
            count++;
            if (count > max) { max = count; }
        }
        else {
            j++;
            count--;
        }     
    }
    while (i<n) {
        i++;
        count++;
        if (count > max) { max = count; }
    }
    while (j<n) {
        j++;
        count--;
    }
    return max;
}



int main() {
    int arr[] = {10, 11, 13, 14, 13};
    int dep[] = {12, 16, 15, 17, 17};

    cout << count_max_intersection(arr, dep, 5) << endl;
    cout << count_max_intersection2(arr, dep, 5) << endl;

    return 0;
}
