#include<bits/stdc++.h>
using namespace std;

//Time complexity: O(n)
vector<int> nextGreaterElement(vector<int> v){
    vector<int> res;
    stack<int> s;
    for(int i=v.size()-1; i>=0; i--){
        while(!s.empty() and s.top() <= v[i]){
            s.pop();
        }
        if(s.empty()){
            res.push_back(-1);
        }else{
            res.push_back(s.top());
        }
        s.push(v[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> inp = {39, 4, 5, 2, 25, 23, 38};
    vector<int> res = nextGreaterElement(inp);
    for(auto x: res){
        cout << x << " ";
    }
    return 0;
}