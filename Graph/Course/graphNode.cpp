#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    list<string> nbrs;

    Node(string name){
        this->name = name;
    }
};

class Graph {
    unordered_map<string, Node*> m;
public:
    Graph(vector<string> cities){
        for(auto city: cities){
            m[city] = new Node(city);
        }
    }

    void addEdge(string x, string y, bool undire = false){
        m[x]->nbrs.push_back(y);
        if(undire){
            m[y]->nbrs.push_back(x);
        }
    }

    void printGraph() {
        for(auto cityPair: m){
            string city = cityPair.first;
            cout << city << "->";
            for(auto nbr: cityPair.second->nbrs){
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    return 0;
}