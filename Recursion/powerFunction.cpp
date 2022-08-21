//power function: find the power of a number using a recursive function. Both power and number are given as input.
//Time complexity: O(logn)
//Space complexity: O(logn)
#include<iostream>
using namespace std;

int powerFunction(int power, int base) {
    //base case
    if(power == 0){
        return 1;
    }
    //recursive case
    return powerFunction(power - 1, base)*base;
}

int optimizedPowerFunction(int power, int base){
    //base case
    if(power == 0){
        return 1;
    }
    //recursive case
    if(power&1){
        int ans = optimizedPowerFunction(power/2, base);
        return ans*ans*base;
    }
    int ans = optimizedPowerFunction(power/2, base);
    return ans*ans;
}

int main() {
    int power, base;
    cin >> power >> base;

    cout << powerFunction(power, base) << " " << optimizedPowerFunction(power, base);
    return 0;
}