#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }

    void addEdge(int i, int j, bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printGraph() {
        for(int i=0; i<V; i++){
            cout << i << "-->";
            for(auto x: l[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }

    void bfs(int source) {
        queue<int> q;
        q.push(source);
        int visited[V] = {0};
        visited[source] = 1;
        //cout << "Okay";
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto nbr: l[top]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = 1;
                }
            }
            //cout << "Okat";
            cout << top << " ";
        }
        //cout << "Ok";
    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.printGraph();
    g.bfs(1);
    return 0;
}