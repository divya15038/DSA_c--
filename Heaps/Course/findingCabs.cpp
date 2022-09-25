#include<bits/stdc++.h>
using namespace std;

class compare {
public:
    bool operator()(pair<int, int> a, pair<int, int>b){
        return a.first*a.first + a.second*a.second > b.first*b.first + b.second*b.second;
    }
};

int main() {
    vector<vector<int>> v= {{1, 1}, {2, 1}, {3, 2}, {0, 1}, {2, 3}};
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> c;
    for(auto x: v){
        c.push(make_pair(x[0], x[1]));
    }
    int k = 3;
    vector<vector<int>> res;
    while(k){
        res.push_back({c.top().first, c.top().second});
        c.pop();
        k--;
    }

    for(auto x: res){
        cout << x[0] << "," << x[1] << endl;
    }
    return 0;
}