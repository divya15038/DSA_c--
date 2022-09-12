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

void printLinkedList(node *head){
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}
void insertNode(node *head, int data){
    node* newNode = new node(data);
    newNode->next = head->next;
    head->next = newNode;
    return;
}
node* alternateMerge(node * root1, node* root2){
    //Complete this function 
    node **head1 = &root1;
    node **head2 = &root2;
    node* lt1 = *head1;
    node* lt2 = *head2;
    printLinkedList(*head1);
    printLinkedList(*head2);
    node *temp;
    
    while((*head1)!=NULL and (*head2)!= NULL){
        insertNode((*head1), (*head2)->data);
        if((*head1)->next->next == NULL)
            temp = (*head1)->next;
        (*head1) = (*head1)->next->next;
        (*head2) = (*head2)->next;
        //printLinkedList(lt1);
    }
    while((*head2)!=NULL){
        insertNode(temp, (*head2)->data);
        temp = temp->next;
        (*head2) = (*head2)->next;
    }
    //printLinkedList(root1);
    return lt1;
}