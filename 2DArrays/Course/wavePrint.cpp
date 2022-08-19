//wave print: print the elements in the given 2d array in the form of reverse wave that is:
/* 1 2 3 4
   5 6 7 8 
   9 10 11 12
Output: 4 8 12 11 7 2 2 6 10 9 5 1*/
#include<iostream>
using namespace std;

void wavePrint(int row, int col, int arr[][10]) {
    int colEnd = col - 1;
    while(colEnd>=0){
        for(int i=0; i<row; i++){
            cout << arr[i][colEnd] << " ";
        }
        colEnd--;
        for(int j=row-1; j>=0; j--){
            if(colEnd<0){
                break;
            }
            cout << arr[j][colEnd] << " ";
        }
        colEnd--;
    }
}

int main() {
    int arr[][10] = {{1, 2, 3},
                     {5, 6, 7},
                     {9, 10, 11},
                     {13, 14, 15}};
    int row, col;
    cin >> row >> col;

    wavePrint(row, col, arr);
    return 0;
}