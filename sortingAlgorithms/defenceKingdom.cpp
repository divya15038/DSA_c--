//defence kingdom: We are provided with a chessboard with dimensions H*W. A tower protects all the cells in the column and row of the cell it stands in. We are asked to find the largest undefended area on the board.
//Time complexity: O(nlogn)

//1.Brute force approach: The largest undefeated area will be the multiple of largest H and largest W which are undefended. Firsty, sort on the basis of x axis and find the largest difference between two consecutive x coordinates.
//Repeat similar process for y coordinates. Then, our answer will be the multiple of two.
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int largestArea(int H, int W, vector<pair<int, int>> loc) {
    loc.insert(loc.begin(), {1, 1});
    sort(loc.begin(), loc.end());
    loc.push_back({H+1, 0});
    int maxW = INT_MIN, maxH = INT_MIN;
    for(int i=0; i<loc.size()-1; i++){
        int currDiff = loc[i+1].first - loc[i].first;
        if(currDiff > maxW) {
            maxW = currDiff;
        }
    }
    loc.pop_back();
    sort(loc.begin(), loc.end(), compare);
    loc.push_back({0, W+1});
    for(int i=0; i<loc.size()-1; i++){
        int currDiff = loc[i+1].second - loc[i].second;
        if(currDiff > maxH) {
            maxH = currDiff;
        }
    }
    maxH --;
    maxW --;
    return maxH * maxW;
}

int main() {
    int H, W; 
    cin >> H >> W;

    vector<pair<int, int>> loc = {{3, 8}, {11, 2}, {8, 6}};
    cout << largestArea(H, W, loc);
    return 0;
}