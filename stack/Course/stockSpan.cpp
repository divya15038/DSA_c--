#include <bits/stdc++.h>
using namespace std;
//Brute force
//Time Complexity: O(n^2)
void findSpan(vector<int> &v, stack<int> stock){
    int top = stock.top();
    stock.pop();
    int count = 1;
    while((!stock.empty()) and stock.top() <= top){
        stock.pop();
        count++;
    }
    v.push_back(count);
    return;
}

//Time Complexity: O(n)
void findSpan1(vector<int> &span, vector<int> stock){
    stack<int> s;
    s.push(0);
    span.push_back(1);
    for(int i=1; i<stock.size(); i++){
        int currPrice = stock[i];
        while((!s.empty()) and stock[s.top()]<=currPrice){
            s.pop();
        }
        if(!s.empty()){
            span.push_back(i-s.top());
        }else{
            span.push_back(i+1);
        }
        s.push(i);
    }

}

vector<int> stockSpanner(vector<int> &stocks){
    stack<int> stock;
    vector<int> r;
    for(auto x: stocks){
        stock.push(x);
    }
    while(!stock.empty()){
        findSpan(r, stock);
        stock.pop();
    }
    reverse(r.begin(), r.end());
    return r;
}

int main(){
    vector<int> stock = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockSpanner(stock);
    for(auto x: res){
        cout << x << " ";
    }
    cout << endl;
    vector<int> span;
    findSpan1(span, stock);
    for(auto x: span){
        cout << x << " ";
    }
    return 0;
}