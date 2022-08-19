//sorted array search: Search for an element in the given sorted 2d array(sorted row and column wise). Since matrix is sorted,
//if we start searchin from either top right corner or bottom left corner moving in one direction will increase values whereas moving in othe direction will decrease values.
//Time Complexity: O(n)
#include<iostream>
using namespace std;

pair<int, int> findElementSortedMatrix(int arr[][4], int rows, int cols, int key) {
    //starting from the upper right element
    int rowIdx = 0;
    int colIdx = cols - 1;
    while(colIdx>0 and rowIdx<rows) {
        if(arr[rowIdx][colIdx] == key){
            return make_pair(rowIdx, colIdx);
        } else if(arr[rowIdx][colIdx] > key){
            colIdx--;
        } else {
            rowIdx++;
        }
    }
    return make_pair(-1, -1);
}   

int main() {
    int arr[][4] = {{1, 2, 3, 4},
                    {5, 6, 7, 8},
                    {9, 10, 11, 12},
                    {13, 14, 15, 16}};
    
    int row, col, key;
    cin >> row >> col >> key;

    pair<int, int> idx = findElementSortedMatrix(arr, row, col, key);
    if(idx.first != -1){
        cout << "Element was found at index:" << idx.first << "," << idx.second << endl;
    } else {
        cout << "Element was not found in the given matrix." << endl;
    }
    return 0;
}