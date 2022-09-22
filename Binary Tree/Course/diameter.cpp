#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int d):data(d),left(NULL),right(NULL){};
};

Node* buildTree() {
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

void printTree(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    //cout << max(h1, h2) << endl;
    return 1 + max(h1, h2);
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

int diameter(Node* root){
    if(root == NULL){
        return 0;
    }

    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    return max(D1, max(D2, D3));
}

class HDpair {
public:
    int height;
    int diameter;
};

HDpair Diameter(Node* root) {
    HDpair p;
    //base case
    if(root == NULL) {
        p.diameter = p.height = 0;
        return p;
    }
    //recursive case
    HDpair Left = Diameter(root->left);
    HDpair Right = Diameter(root->right);

    p.height = max(Left.height, Right.height)+1;

    int D1 = Left.height + Right.height;
    int D2 = Left.diameter;
    int D3 = Right.diameter;
    p.diameter = max(D1, max(D2, D3));
    return p;
}

int main() {
    Node* root = buildTree();
    //levelOrderPrint(root);
    cout << height(root);
    cout << endl << diameter(root);
    cout << endl << Diameter(root).diameter;
    return 0;
}