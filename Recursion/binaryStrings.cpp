//binary strings: Given an integer n, return a vector containing binary strings of size n with no consecutive ones.
//Time Complexity: O(2^n)
//Space complexity: O(n)
#include<bits/stdc++.h>
using namespace std ;
vector<string> res;

void generateAllBinaryStrings(int k, char str[], int n) {
    if(k == n){
        str[n] = '\0';
        res.push_back(str);
        return ;
    }
    //if the previous value is one, only 0 can be inserted
    if(str[n-1] == '1'){
        str[n] = '0';
        generateAllBinaryStrings(k, str, n+1);
    }
    else if(str[n-1] == '0'){
        str[n] = '1';
        generateAllBinaryStrings(k, str, n+1);
        str[n] = '0';
        generateAllBinaryStrings(k, str, n+1);
    }


}

void generateBinaryStrings(int n){
    //base case
    if(n <= 0) {
        return;
    }
    //recursive case
    char str[n];
    //cases starting with 0
    str[0] = '0';
    generateAllBinaryStrings(n, str, 1);

    //cases starting with one
    str[0] = '1';
    generateAllBinaryStrings(n, str, 1);
    return;
}

int main() {
    int n; 
    cin >> n;

    generateBinaryStrings(n);
    for(auto x: res){
        cout << x << endl;
    }
    return 0;
}