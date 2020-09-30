#include <iostream>
#include <string>
using namespace std;


// The main function that sort the given string arr[] in
// alphabatical order
// return the sorted char array
char* countSort(char arr[])
{
    int max {0};
    int N {0};
    // O(N), S(1)
    for (int i=0; i<INT64_MAX; ++i) {
        if (int(arr[i])>max) {
            max = int(arr[i]);
        }
        if (int(arr[i])==0) {
            N = i;
            break;
        }
    }

    int count[max]; // S(K)
    // Initialize: O(K)
    for (int i=0; i<max; ++i) {
        count[i] = 0;
    }

    // insert counts: O(N)
    for (int i=0; i<N; ++i) {
        count[int(arr[i])-1]++;
    }
    // Integrate: O(K)
    for (int i=1; i<max; ++i) {
        count[i] += count[i-1];
    }

    char res[N]; // S(N)
    
    // O(N)
    for (int i=N-1; i>=0; --i) {
        res[count[int(arr[i])-1]-1] = arr[i];
        count[int(arr[i])-1]--;
    }

    // O(N)
    for (int i=0; i<N; ++i) {
        arr[i] = res[i];
    }
    return arr;
}


int main() {
    char arr[] = "geeksforgeeks";
    cout << countSort(arr) << endl;
}