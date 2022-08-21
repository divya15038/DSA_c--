//number spell: given a number return a string so that 2021 converts to two zero two one.
//Time complexity: O(N)
//Space complexity: O(N)
#include<iostream>
using namespace std;

string spell[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string numToString(int n) {
    //base case
    if(n == 0){
        return "";
    }
    //recursive case
    string res = numToString(n/10);
    res = res + spell[n%10] + " ";
    return res;
}

int main() {
    int n;
    cin >> n;

    cout << numToString(n);
    return 0;
}