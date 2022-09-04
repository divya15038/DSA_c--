//soduko solver: Solve a nxn soduko
//Time complexity:
//Space complexity:
#include<iostream>
using namespace std;

bool isSafe(int mat[][20], int n, int i, int j, int num){
    //check for num in row and col
    for(int k=0; k<n;k++){
        if(mat[i][k] == num || mat[k][j] == num){
            return false;
        }
    }

    //check for num in 3x3 grid
    int sx = (i/3) * 3;
    int sy = (j/3) * 3;
    for(int x=sx; x<sx+3; x++){
        for(int y=sy; y<sy+3; y++){
            if(mat[x][y] == num){
                return false;
            }
        }
    }
    return true;
}

void printArray(int mat[][20], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}
bool solveSudoku(int n, int mat[][20], int i, int j) {
    //base case
    if(i == n) {
        printArray(mat, n);
        return true;
    }
    //recursive case
    if(j == n){
        return solveSudoku(n, mat, i+1, 0);
    }
    if(mat[i][j] != 0){
        return solveSudoku(n, mat, i, j+1);
    }

    for(int no=1; no<=9; no++){
        if(isSafe(mat, n, i, j, no)){
            mat[i][j] = no;
            bool success = solveSudoku(n, mat, i, j+1);
            if(success){
                return true;
            }
        }
    }
    //backtrack if no number fits
    mat[i][j] = 0;
    return false;
}

int main() {
    int n = 9;
	int mat[20][20] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};


    if(!solveSudoku(n, mat, 0, 0)){
    	cout<<"No solution exists!";
    }
    return 0;
}