//count the number of set bits in the given binary number
//Time Complexity: O(logn) n-decimal number
#include<iostream>
using namespace std;

int countSetBits(int n) {
    int count = 0;
    while(n>0) {
        int lastBit = (n&1);
        count += lastBit;
        n = n >> 1;
    }
    return count;
}

int main() {
    int n = 15;
    cout << countSetBits(n);
    return 0;
}