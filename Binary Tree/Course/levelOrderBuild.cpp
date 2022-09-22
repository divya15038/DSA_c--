#include<iostream>
#include<vector>
#include<algorithm>
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

int heightOfTree(Node* root){
    if(root == NULL){;
        return 0;
    }
    int h1 = heightOfTree(root->left);
    int h2 = heightOfTree(root->right);
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

int sumBT(Node* root){
    queue<Node*> q;
    int res = 0;
    q.push(root);

    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        res += temp->data;
    }
    return res;
}

vector<int> printKthLevel(Node* root, int k){
    vector<int> res;
    if(k == 0){
        res.push_back(root->data);
        return res;
    }
    queue<Node*> q;
    int i = 0;
    q.push(root);
    q.push(NULL);

    while(i<k and !q.empty()){
        Node* top = q.front();
        q.pop();
        if(top == NULL){
            q.push(NULL);
            i++;
        }
        else{
            if(top->left != NULL){
                q.push(top->left);
            }
            if(top->right != NULL){
                q.push(top->right);
            }
        }
    }
    int prev = q.front()->data;
    while(q.front() != NULL){
        int prev = q.front()->data;
        res.push_back(prev);
        //cout << q.front()->data << " ";
        q.pop();
        if(q.front() != NULL){
            int curr = q.front()->data;
            if(curr == prev){
                q.pop();
            }
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<int> data = {2, 7, 5, -1, 9, -1, 1, 11, 4, -1, -1};
    Node* root = buildTreeLevel(data);
    //levelOrderPrint(root);
    //cout << heightOfTree(root);
    //vector<int> res = printKthLevel(root, 2);
    //for(auto x: res){
    //    cout << x << " ";
    //}
    cout << sumBT(root);
    return 0;
}