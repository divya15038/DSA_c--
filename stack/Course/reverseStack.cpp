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
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}