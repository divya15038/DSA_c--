#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *right, *left;
    Node(int d):data(d), left(NULL), right(NULL){};
};

Node* buildTree(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    
    Node* n = new Node(data);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

void printPostorder(Node* root){
    if(root == NULL){
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}
int main(){
    Node* root = buildTree();
    printPostorder(root);
    return 0;
}