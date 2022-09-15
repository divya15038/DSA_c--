#include<iostream>
#include<vector>
using namespace std;

int i = 0;
class Node{
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

void printInOrder(Node* root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}
int main() {
    Node* root = buildTreePreorder();
    printInOrder(root);
    return 0;
}