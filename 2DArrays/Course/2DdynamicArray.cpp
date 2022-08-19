//2d dynamic array: Create a 2d dynamic array
#include<iostream>
using namespace std;

int** create2dDynamicArray(int rows, int cols){
    //create a pointer to pointers of rows
    int ** arr = new int*[rows];
    for(int i=0; i<rows; i++){
        arr[i] = new int[cols];
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            arr[i][j] = i+j;
        }
    }
    return arr;
}

int main() {
    int row, col;
    cin >> row >> col;
    int ** arr = create2dDynamicArray(row, col);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}