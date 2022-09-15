#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
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

int main() {
    Node* root = buildTree();
    levelOrderPrint(root);
    return 0;
}