#include<bits/stdc++.h>
using namespace std;

queue<int> interLeave(queue<int> q){
    queue<int> q1;
    int n = q.size();
    int i = 0;
    while(i<(n/2)){
        q1.push(q.front());
        q.pop();
        i++;
    }
    while(!q1.empty()){
        q.push(q1.front());
        q1.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    queue<int> res = interLeave(q);

    while(!res.empty()){
        cout << res.front() << " ";
        res.pop();
    }
    return 0;
}