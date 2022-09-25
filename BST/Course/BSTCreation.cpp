#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;
    Node(int d):data(d), left(NULL), right(NULL){};
};

Node* insert(Node* root, int key) {
    //base case
    if(root == NULL){
        return new Node(key);
    }
    //recursive case
    if(key < root->data){
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }
    return root;
}

void printInOrder(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    //recursive case
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
    return;
}

Node* searchBST(Node* root, int key) {
    //base case
    if(root == NULL){
        return NULL;
    }
    //recursive case
    if(root->data == key){
        return root;
    } else if(root->data < key){
        return searchBST(root->right, key);
    } else {
        return searchBST(root->left, key);
    }
    return NULL;
}

Node* findMin(Node* root){
    while(root->left){
        root = root->left;
    }
    return root;
}

Node* deletionBST(Node* root, int key){
    //base case 
    if(root == NULL){
        return NULL;
    }
    //recursive case
    if(root->data < key){
        root->right = deletionBST(root->right, key);
    } else if(root->data > key){
        root->left = deletionBST(root->left, key);
    } else {
        //3 cases:
        //0 children
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        }
        //1 child
        else if(root->right == NULL){
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else if(root->left == NULL){
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        // 2 children
        else {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deletionBST(root->right, temp->data);
        }
    }
    return root;
}
//int sum = 0;
int printInRange(Node *root, int s, int e){
    //base case
    if(root == NULL){
        return 0;
    }
    //recursive case
    int sum = 0;
    if(root->data >= s and root->data <= e){
        sum += printInRange(root->left, s, e);
        sum +=  root->data;
        sum += printInRange(root->right, s, e);
    } else if(root->data < s){
        sum += printInRange(root->right, s, e);
    } else {
        sum += printInRange(root->left, s, e);
    }
    return sum;
}

void Root2LeafPaths(Node* root, vector<int> &path) {
    //base case
    if(root == NULL){
        return;
    }
    if(root->right == NULL and root->left == NULL){
        path.push_back(root->data);
        for(auto x: path){
            cout << x << " ";
        }
        cout << endl;
        path.pop_back();
        return;
    }
    //recursive case
    path.push_back(root->data);
    Root2LeafPaths(root->left, path);
    Root2LeafPaths(root->right, path);
    //backtracking
    path.pop_back();
}

Node* mirrorBST(Node * root){
    //complete this method
    if(!root){
        return NULL;
    }
    Node* temp = root->right;
    root->right = root->left;
    root->left = temp;
    root->right = mirrorBST(root->right);
    root->left = mirrorBST(root->left);
    return root;
}

bool isBST(Node * root){
    //complete this method
    if(root == NULL){
        return true;
    }
    if((root->left == NULL or root->data >= root->left->data) and (root->right == NULL or root->data <= root->right->data)){
        return isBST(root->right);
        return isBST(root->left);
    }else {
        return false;
    }
}
int main(){
    Node *root = NULL;
    int arr[] = {8, 3, 6, 1, 4, 7, 13, 14, 10};
    for (auto x: arr){
        root = insert(root, x);
    }
    printInOrder(root);
    cout <<endl<< isBST(root);
    return 0;
}