//spiral print: write a function that prints a n x m matrix in a spiral format starting from (0, 0) element.
//Time complexity: O(n*m)
#include<iostream>
using namespace std;

void spiralPrint(int row, int col, int arr[][10]) {
    int rowStart = 0;
    int rowEnd = row-1;
    int colStart = 0;
    int colEnd = col-1;

    while(rowStart<=rowEnd && colStart<=colEnd) {
        //print the start row
        for(int i=colStart; i<=colEnd; i++){
            cout << arr[rowStart][i] << " ";
        }

        //print the end column
        for(int j=rowStart + 1; j<=rowEnd; j++){
            cout << arr[j][colEnd] << " ";
        }

        //print the end row
        for(int i=colEnd-1; i>= colStart; i--){
            //to avoid printing duplicate rows if rows>cols
            if(colStart == colEnd){
                break;
            }
            cout << arr[rowEnd][i] << " ";
        }

        //print the start col
        for(int j=rowEnd-1; j>=rowStart+1; j--){
            //to avoid printing duplicate cols if cols>rows
            if(rowStart == rowEnd){
                break;
            }
            cout << arr[j][colStart] << " ";
        }
        rowStart++;
        rowEnd--;
        colStart++;
        colEnd--;
    }
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    int arr[][10] = {{1, 2, 3}, 
                    {5, 6, 7}};
    spiralPrint(rows, cols, arr);
    return 0;
}