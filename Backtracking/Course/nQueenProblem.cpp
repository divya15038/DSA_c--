//1. Find if it is possible to place n queens in a nxn grid and print one configuration.
//Time Complexity: O(n^n)
//Space complexity: O(n)
//2. Find the number of ways to place a queen in a nxn grid and print all configurations.
//Time complexity: 
//Space Complexity:
#include<iostream>
using namespace std;

bool isSafe(int n, int y, int x, int mat[][20]){
    //check for column 
    for(int i=0; i<y; i++){
        if(mat[i][x] == 1){
            return false;
        }
    }

    //check for right diagnol
    int i = y;
    int j = x;
    while(i>=0 and j>=0){
        if(mat[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    i=y;
    j=x;
    //check for left diagnol
    while(i>=0 and j<=n-1){
        if(mat[i][j] == 1){
            return false;
        }
        i--;
        j++;
    }
    return true;
}

void printArray(int arr[][20], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool nQueenPossible(int n, int mat[][20], int i){
    //base case
    if(i == n){
        printArray(mat, n);
        return true;
    }

    //recursive case
    for(int j=0; j<n; j++){
        if(isSafe(n, i, j, mat)){
            mat[i][j] = 1;
            bool success = nQueenPossible(n, mat, i+1);
            if(success){
                return true;
            }
            //backtrack to previous row and look for next j to place queen
            mat[i][j] = 0;
        }
    }
    //if no j found no possible configuuration
    return false;
}

int nQueenWays(int n, int mat[][20], int i){
    //base case
    if(i == n){
        printArray(mat, n);
        cout << endl;
        return 1;
    }

    //recursive case
    int ways = 0;
    for(int j=0; j<n; j++){
        if(isSafe(n, i, j, mat)){
            mat[i][j] = 1;
            ways += nQueenWays(n, mat, i+1);
            //backtrack to previous row and look for next j to place queen
            mat[i][j] = 0;
        }
    }
    //if no j found no possible configuuration
    return ways;    
}

int main() {
    int mat[20][20] = {0};
    int n;
    cin >> n;

    cout << nQueenWays(n, mat, 0);
    return 0;
}