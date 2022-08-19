//rotate image: Rotate a given square matrix by 90 degrees.
//Time complexity: O(n^2)
#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> &matrix) {
    int colStart = 0;
    int colEnd = matrix[0].size() - 1;
    int rowStart = 0;
    int rowEnd = matrix.size() - 1;
    while(colStart <= colEnd){
        for(int i=rowEnd; i>=0; i--){
            matrix[colStart].push_back(matrix[i][colStart]);
        }
        colStart++;
    }


    for(int i=0; i<matrix.size(); i++){
        matrix[i].erase(matrix[i].begin(), matrix[i].begin() + rowEnd + 1);
    }
}

int main() {
    vector<vector<int>> img = {{1, 2, 3, 4},
                                {4, 5, 6, 7}, 
                                {7, 8, 9, 10},
                                {11, 12, 13, 14}};
    
    rotate(img);
    for(int i=0; i<img.size(); i++){
        for(int j=0; j<img[i].size(); j++){
            cout << img[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}