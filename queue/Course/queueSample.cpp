#include<iostream>
#include "queue.h"
using namespace std;

int main(){
    Queue<int> q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.isEmpty()){
        cout << q.getFront() << " ";
        q.pop();
    }

    return 0;
}