//binary string to number: convert a given binary string to its decimal equivalent.
//Time complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(string input) {
    int baseTwo = 1;
    int decimal = 0;
    for(int i=0; i<input.length(); i++){
        int digit = input[i] - '0';
        decimal += digit*baseTwo;
        baseTwo *= 2;
    }
    return decimal;
}

int main() {
    string binary = "1001";
    cout << binaryToDecimal(binary);
    return 0;
}