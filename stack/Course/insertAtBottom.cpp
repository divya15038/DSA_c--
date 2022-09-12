#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int data){
    stack<int> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(data);
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
    return;
}

void insertAtBottomRecursive(stack<int> &s, int data){
    //base case
    if(s.empty()){
        s.push(data);
        return;
    }
    //recursive case
    int val = s.top();
    s.pop();
    insertAtBottomRecursive(s, data);
    s.push(val);
    return;
}   
int main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    insertAtBottomRecursive(s, 1);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}