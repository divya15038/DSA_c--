#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int d):data(d), left(NULL), right(NULL){};
};

Node* buildTreeLevel(vector<int> data){
    queue<Node*> tree;
    int i = 0;
    Node* root = new Node(data[0]);
    tree.push(root);

    while(i<data.size() and !tree.empty()){
        Node* n = tree.front();
        i++;
        if(data[i] != -1){
            n->left = new Node(data[i]);
            tree.push(n->left);
        }
        i++;
        if(data[i] != -1){
            n->right = new Node(data[i]);
            tree.push(n->right);
        }
        tree.pop();
    }
    return root;
}

void levelOrderPrint(Node* root){
    queue<Node*> node;
    node.push(root);
    node.push(NULL);

    while(node.size() != 1){
        Node* topNode = node.front();
        node.pop();
        if(topNode == NULL){
            node.push(NULL);
            cout << endl;
            continue;
        }
        if(topNode->left!=NULL){
            node.push(topNode->left);
        }
        if(topNode->right != NULL){
            node.push(topNode->right);
        }
        cout<< topNode->data << " ";
    } 
}

int main(){
    vector<int> data = {1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1};
    Node* root = buildTreeLevel(data);
    levelOrderPrint(root);
    return 0;
}