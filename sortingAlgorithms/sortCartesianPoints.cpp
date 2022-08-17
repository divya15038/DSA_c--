//sort cartesian points: This algorithm sorts the cartesian points on the basis of their x axis values. If the x values are same sort on the basis of y values.
//Time complexity: O(nlogn)
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first){
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

void sortCartesianPoints(vector<pair<int, int>> &cart) {
    int n = cart.size();
    sort(cart.begin(), cart.end(), compare);
}

int main() {
    vector<pair<int, int>> cartPoints = {{3, 4}, {2, 3}, {3, 7}, {1, 5}, {3, 4}};
    sortCartesianPoints(cartPoints);
    for(int i=0; i<cartPoints.size(); i++){
        cout << cartPoints[i].first << "," << cartPoints[i].second << " ";
    }
    return 0;
}