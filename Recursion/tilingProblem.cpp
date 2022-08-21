//tiling Problem: We are given a floor of size n x m, we need to find the number of ways to fill it with tiles of size n x m.
//Time complexity: O(2^n)
//Space complexity: O(N)
#include<iostream>
using namespace std;

int numOfWays(int n, int m) {
    //base case
    if(n < m){
        return 1;
    }
    //recursive case
    return numOfWays(n-1, m) + numOfWays(n-m, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    cout << numOfWays(n, m);
    return 0;
}
