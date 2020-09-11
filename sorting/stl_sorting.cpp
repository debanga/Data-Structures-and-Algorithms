// STL Sorting
// O(nlogn)
// Internally uses quick, heap, or insertion sort
#include <iostream>
#include <algorithm>

struct P {
    int x;
    int y;
};

void print(int arr[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void print_point(P a[], int n) {
    for (int i=0; i<n; ++i) {
        std::cout << "(" << a[i].x << "," << a[i].y << ") ";
    }
    std::cout << std::endl;
}

bool custom_logic(P a, P b) {
    return a.x > b.x;
}

int main() {
    int arr[] = {1, 20, 4, 9, 2};
    print(arr,5);
    std::sort(arr, arr+5); // note we add upto 1 later than the last element
    print(arr,5);
    std::sort(arr, arr+5, std::greater<int>());
    print(arr,5);
    P pt[] = {{4,2}, {1,2}, {3,4}};
    std::sort(pt, pt+3, custom_logic);
    print_point(pt, 3);
}