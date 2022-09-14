#include<iostream>
#include<queue>
using namespace std;

class Stack{
    queue<int> q1, q2;

public:
    void push(int data){
        if(q1.empty()){
            q2.push(data);
        }else{
            q1.push(data);
        }
    }

    void pop(){
        if(q1.empty()){
            while(!q2.empty()){
                int front = q2.front();
                q2.pop();
                if(q2.empty()){
                    break;
                }
                q1.push(front);
            }
        }else{
            while(!q1.empty()){
                int front = q1.front();
                q1.pop();
                if(q1.empty()){
                    break;
                }
                q2.push(front);
            }
        }
    }

    int front(){
        if(q1.empty()){
            while(!q2.empty()){
                int front = q2.front();
                q2.pop();
                if(q2.empty()){
                    q1.push(front);
                    return front;
                }
                q1.push(front);
            }
        }else{
            while(!q1.empty()){
                int front = q1.front();
                q1.pop();
                if(q1.empty()){
                    q2.push(front);
                    return front;
                }
                q2.push(front);
            }
        }
        return -1;
    }

    bool isEmpty(){
        return (q1.empty() and q2.empty());
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        cout << s.front() << " ";
        s.pop();
    }
    return 0;
}