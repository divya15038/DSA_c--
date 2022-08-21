//fibonacci series: Compute the nth term of the fibonacci series.
//Time Complexity: O(2^n) binary tree
//Space Complexity: O(n)
#include<iostream>
using namespace std;

int fibonacciTerm(int n){
    //base case
    if(n==0 || n==1){
        return n;
    }
    //resursive case
    return fibonacciTerm(n-1) + fibonacciTerm(n-2);
}

int main(){
    int n;
    cin >> n;

    cout << fibonacciTerm(n) << endl;
    return 0;
}