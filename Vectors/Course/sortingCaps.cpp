//sorting cabs: sort cartesian points according to their distance from the origin.
//Time complexity: O(nlogn)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
}

int main() {
    vector<pair<int, int>> v = {{2, 3}, {1, 2}, {3, 4}, {2, 4}, {1, 4}};
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++){
        cout << v[i].first << "," << v[i].second << endl;
    }
    return 0;
}