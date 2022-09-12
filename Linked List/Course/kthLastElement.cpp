#include<bits/stdc++.h>
using namespace std;


class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

int kthLastElement(node * head,int k){
    //Complete this function to return kth last element
    if(head == NULL || head->next == NULL){
        return head->data;
    }
    node* temp = head;
    int count = 1;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    temp = head;
    int diff = count-k;
    while(diff > 0){
        temp = temp->next;
        diff--;
    }
    //cout << temp->val;
    return temp->data;
}