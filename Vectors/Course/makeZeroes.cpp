// make zeroes: Given a 2d matrix, make both row and column containing zero as zero.
//Time Complexity: O(n^2)
#include<iostream>
#include<vector>
using namespace std;

void makeZeroes(vector<vector<int>> &vec) {
    vector<int> row, col;
    for(int i=0; i<vec.size(); i++){
        for(int j=0; j<vec[0].size(); j++){
            if(vec[i][j] == 0){
                row.push_back(i);
                col.push_back(j);
            }
        }
    }

    for(auto x: row){
        for(int i=0; i<vec[0].size(); i++){
            vec[x][i] = 0;
        }
    }

    for(auto x: col){
        for(int i=0; i<vec.size(); i++){
            vec[i][x] = 0;
        }
    }
}

int main() {
    vector<vector<int>> v = {{1, 2, 3, 4},
                             {5, 0, 7, 8},
                             {9, 10, 11, 0},
                             {13, 14, 15, 16}};

    makeZeroes(v);
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[0].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}