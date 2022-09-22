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

int minDepth(Node *root) {
    // Your code here
    if(root == NULL){
        return 0;    
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

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

bool isSymmetric(Node* root) {
    //your code goes here
    if(height(root->left) != height(root->right)){
        return false;
    }
    queue<Node*> left, right;
    left.push(root->left);
    right.push(root->right);

    while(!left.empty() and !right.empty()){
        Node* left_front = left.front();
        left.pop();
        Node* right_front = right.front();
        right.pop();

        if(left_front == NULL and right_front == NULL){
            continue;
        } else if(left_front == NULL and right_front != NULL) {
            return false;
        } else if(left_front != NULL and right_front == NULL) {
            return false;
        }
        if(left_front->data != right_front->data){
            return false;
        }
        left.push(left_front->left);
        left.push(left_front->right);
        right.push(right_front->right);
        right.push(right_front->left);
    }
    return true;
}

int evalTree(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }  
    if(root->key != "+" && root->key != "-" && root->key != "*" && root->key != "/"){
        return stoi(root->key);
    }
    
    if(root->key == "+")
        return evalTree(root->left) + evalTree(root->right);
    else if(root->key == "-")
        return evalTree(root->left) - evalTree(root->right);
    else if(root->key == "*")
        return evalTree(root->left)*evalTree(root->right);
    else if(root->key == "/")
        return evalTree(root->left)/evalTree(root->right);
    return 0;
}

int main() {
    Node* root = buildTree();
    levelOrderPrint(root);
    //cout << height(root);
    //cout << endl << minDepth(root);
    //cout << isSymmetric(root);
    //cout << endl << diameter(root);
    //cout << endl << Diameter(root).diameter;
    cout << evalTree(root);
    return 0;
}