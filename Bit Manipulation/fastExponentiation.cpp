//fast exponentiation: calculates the a raised to power n in logn time as compared to the usual n times using bit manipulation.
//Time Complexity: O(logn)
#include<iostream>
using namespace std;

int fastExponentiation(int base, int power) {
    int ans = 1;
    while(power>0) {
        int lastBit = (power&1);
        if(lastBit){
            ans *= base;
        }
        base = base*base;
        power = power >> 1;
    }
    return ans;
}

int main() {
    int base, power;
    cin >> base >> power;

    cout << fastExponentiation(base, power);
    return 0;
}