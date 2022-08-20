//convert a given decimal number to its binary equivalent using bitwise operators.
//Time Complexity: O(n)
#include<iostream>
using namespace std;

int decimalToBinary(int n) {
    int binary = 0;
    int base = 1;
    while(n>0){
        binary += base*(n&1);
        base *= 10;
        n = n >> 1;
    }
    return binary;
}

int main() { 
    int n;
    cin >> n;

    cout << decimalToBinary(n) << endl;
    return 0;
}