//factorial: compute the factorial of a given number using the concept of recursion.
//Time complexity: O(n)
//Space complexity: O(n) extra space due to implicit call stack, calls in call stack increase intially, reach the max when function hits 
//base case and then decreases.

#include<iostream>
using namespace std;
 
int factorial(int n){
    //base case
    if(n==0){
        return 1;
    }
    //recursive case
    return factorial(n-1)*n;
}

int main() {
    int n;
    cin >> n;

    cout << "factorial of " << n << ":" << factorial(n);
    return 0;
}