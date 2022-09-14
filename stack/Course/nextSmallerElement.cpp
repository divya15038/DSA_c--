#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmaller(vector<int> inp){
    vector<int> res;
    stack<int> s;
    for(int i=inp.size()-1; i>=0; i--){
        while(!s.empty() and s.top()>=inp[i]){
            s.pop();
        }
        if(s.empty()){
            res.push_back(-1);
        }else{
            res.push_back(s.top());
        }
        s.push(inp[i]);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> inp = {5, 15, 20, 25, 12, 20};
    vector<int> res = nextSmaller(inp);
    for(auto x: res){
        cout << x << " ";
    }
    return 0;
}