#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int> &s, int data){
    //base case
    if(s.empty()){
        s.push(data);
        return;
    }
    //recursive case
    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);
    s.push(temp);
    return;
}

void reverseStack(stack<int> &s){
    //base case
    if(s.empty()){
        return;
    }
    //recursive case
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, temp);
    return;
}

int reverse(int n){
    stack<int> temp;
    int count = 0;
    while(n>0){
        temp.push(n%10);
        n/=10;
        count++;
    }
    reverseStack(temp);
    int base = 1;
    while(count>1){
        base *= 10;
        count--;
    }
    int res = 0;
    while(!temp.empty()){
        res += base*temp.top();
        temp.pop();
        base /= 10;
    }
    return res;
}

int main(){
    int num;
    cin >> num;

    cout << reverse(num);
    return 0;
}