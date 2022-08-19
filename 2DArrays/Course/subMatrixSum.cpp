/*sub matrix Sum: We are given a matrix and two elements, which are the top right and bottom left elements of the submatrix. Find the  
sum of the elements contained in this submatrix 
1.Brute Force approach: Find the sum of the given submatrice by traversing over the elements of the submatrice.
Time Complexity: O(n*m)

2. Prefix sum approach: Find the prefix matrix from the given matrix and then compute the sum of the given submatrix in constant time.
Time Complexity: O(n^2)*/
#include<iostream>
using namespace std;

int computeSubmatrixSum(int arr[][10], int row, int col, int sr, int sc, int er, int ec) {
    //create prefix matrix
    int ans = 0;

    int prefix[row][col] = {0};
    prefix[0][0] = arr[0][0];
    for(int i=1; i<col; i++){
        prefix[0][i] = prefix[0][i-1] + arr[0][i];
    }
    for(int j=1; j<row; j++){
        prefix[j][0] = prefix[j-1][0] + arr[j][0];
    }

    for(int i=1; i<row; i++){
        for(int j=1; j<col; j++){
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + arr[i][j];
        }
    }

    //computing the submatrix sum
    if(sr == 0 and sc == 0) {
        ans += prefix[er][ec];
    } else if(sr == 0) {
        ans += prefix[er][sc-1];
    } else if(sc == 0){
        ans += prefix[sr-1][ec];
    } else {
        ans += prefix[er][ec] - prefix[er][sc-1] - prefix[sr-1][ec] + prefix[sr-1][sc-1];
    }
    return ans;
}

int main(){
    int arr[][10] = {{1, 2, 3, 4, 6},
                    {5, 3, 8, 1, 2},
                    {4, 6, 7, 5, 5},
                    {2, 4, 8, 9, 4} };
    int row, col;
    cin >> row >> col;
    int startRow, startCol, endRow, endCol;
    cin >> startRow >> startCol >> endRow >> endCol;

    cout << computeSubmatrixSum(arr, row, col, startRow, startCol, endRow, endCol);
    return 0;
}