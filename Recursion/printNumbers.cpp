//print numbers from 1..n in decreasing order using a recursive function.
//Time Complexity: O(n)
//Space Complexity: O(n)
#include<iostream>
using namespace std;

void printNumsDecreasing(int n) {
    //base case
    if(n == 0){
        return;
    }
    //recursive case
    cout << n << " ";
    printNumsDecreasing(n-1);
    return;
}

void printNumsIncreasing(int n) {
    //base case
    if(n == 0){
        return;
    }
    //recursive case
    printNumsIncreasing(n -1);
    cout << n << " ";
    return;
}

int main() {
    int n;
    cin >> n;
    printNumsIncreasing(n);
    printNumsDecreasing(n);
    return 0;
}