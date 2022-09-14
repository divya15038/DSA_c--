#include<bits/stdc++.h>
using namespace std;

vector<char> firstnonrepeating(vector<char> str){
    vector<char> res;
    int count[26] = {0};
    queue<char> q;

    for(int i=0; i<str.size(); i++){
        q.push(str[i]);
        count[str[i] - 'a']++;

        while(!q.empty()){
            if(count[q.front() - 'a']>1){
                q.pop();
            }else{
                res.push_back(q.front());
                break;
            }
        }

        if(q.empty()){
            res.push_back('0');
        }
    }
    return res;
}

int main(){
    vector<char> str = {'a', 'a', 'b', 'c', 'b'};
    vector<char> res = firstnonrepeating(str);
    for(auto x: res){
        cout << x << " ";
    }
    return 0;
}