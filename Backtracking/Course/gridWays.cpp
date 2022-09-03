//grid: find the number of ways to reach from the top right to the bottom left box in a 2d mxn grid
//Time complexity: O(2^(n*m))
//Space complexity: O(n | m)
#include<bits/stdc++.h>
using namespace std;

int gridWays_(int size, int i, int j) {
    //base case
    if((i == size-1 && j != size-1) || (i != size -1 && j == size-1)){
        return 1;
    }
    //recursive case
    //go right and then left reduce the number of columns and rows respectively
    return gridWays_(size, i, j+1) + gridWays_(size, i+1, j);

}

int main() {
    int n;
    cin >> n;

    cout << gridWays_(n, 0, 0);
    return 0;
}