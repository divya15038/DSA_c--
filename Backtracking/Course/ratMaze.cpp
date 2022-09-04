//rat maze: Given a nxm maze with O and X, where O represents an availble path whereas X represents the path with an obstacle.
//Time complexity: O(4^(n^2))
//Space complexity: O(n^2)
#include<bits/stdc++.h>
using namespace std;

int ratAndMiceHelper(vector<string> arr, vector<vector<int>> &res, int i, int j, vector<string> &dir, string temp) {
    //base case
    if(i == arr.size()-1 and j == arr[0].size()-1){
        res[i][j] = 1;
        for(int i=0; i<res.size(); i++){
            for(int j=0; j<res[0].size(); j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        dir.push_back(temp);
        return 1;
    }
    //recursive case
    //go down
    int ways = 0;
    if((i != arr.size()-1) and (arr[i+1][j] != 'X') and (res[i+1][j] == 0)){
        res[i+1][j] = 1;
        ways += ratAndMiceHelper(arr, res, i+1, j, dir, temp + 'D');
        res[i+1][j] = 0;
    }

    //go left
    if((j != arr[0].size()-1) and (arr[i][j+1] != 'X') and (res[i][j+1] == 0)){
        res[i][j+1] = 1;
        ways += ratAndMiceHelper(arr, res, i, j+1, dir, temp + 'R');
        res[i][j+1] = 0;
    }
    //go right
    if(j > 0 and (arr[i][j-1] != 'X') and (res[i][j-1] == 0)) {
        res[i][j-1] = 1;
        ways += ratAndMiceHelper(arr, res, i, j-1, dir, temp + 'L');
        res[i][j-1] = 0;
    } 
    //go up
    if(i > 0 and (arr[i-1][j] != 'X') and (res[i-1][j] == 0)) {
        res[i-1][j] = 0;
        ways += ratAndMiceHelper(arr, res, i-1, j, dir, temp + 'U');
        res[i-1][j] = 0;
    }

    return ways;
}

vector<vector<int>> ratAndMice(vector<string> arr) {
    vector<vector<int>> res(arr.size(), vector<int> (arr[0].size(), 0));
    vector<string> dir;
    res[0][0] = 1;
    cout << ratAndMiceHelper(arr, res, 0, 0, dir, "") << endl;
    for(int i=0; i<dir.size(); i++){
        cout << dir[i] << endl;
    }
    return res;
}

int main() {
    vector<string> arr = {"OXXX", "OOXO", "OOXX", "XOOO"};
    vector<vector<int>> res = ratAndMice(arr);
    return 0;
}