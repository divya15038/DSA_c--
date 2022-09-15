#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int d):data(d),left(NULL),right(NULL){};
};

Node* buildTreePreorder(){
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }
    Node* n = new Node(data);
    n->left = buildTreePreorder();
    n->right= buildTreePreorder();
    return n;
}

void printTreePreorder(Node* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    printTreePreorder(root->left);
    printTreePreorder(root->right);
}
int main(){
    Node* root = buildTreePreorder();
    printTreePreorder(root);
    return 0;
}