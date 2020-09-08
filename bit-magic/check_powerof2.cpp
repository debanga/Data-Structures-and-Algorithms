#include <iostream>

// BrianKernighan
bool algo1(int num) {
    if (num==0) return false;
    return (num & (num-1))==0;
}

// Iteratively divide by 2
bool algo2(int num) {
    if (num==0) return false;
    while (num%2!=1) {
        num = (num / 2);
    }
    if (num==1) {return true;}
    else {return false;}
}


int main() {
    int num;
    std::cin >> num;

    std::cout << algo1(num) << std::endl;
    std::cout << algo2(num) << std::endl;
}