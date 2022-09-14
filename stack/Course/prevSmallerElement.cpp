#include<bits/stdc++.h>
using namespace std;

vector<int> prevSmaller(vector<int> inp){
    vector<int> res;
    stack<int> s;
    for(int i=0; i<inp.size(); i++){
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
    return res;
}

int main() {
    vector<int> inp = {4, 10, 5, 8, 20, 15, 3, 12};
    vector<int> res = prevSmaller(inp);
    for(auto x:res){
        cout << x << " ";
    }
        cout << endl;
    return 0;
}