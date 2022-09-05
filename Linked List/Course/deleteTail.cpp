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

node* deleteTail(node * head){
    //Complete this function 
    if(head == NULL){
        return NULL;
    }
    node* temp = head;
    node* prev;
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    delete temp;
    return head;
}