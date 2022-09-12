#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
 

node* bubble_sort_LinkedList_itr(node* head)
{
    // your code goes here
    node *temp = head;
    int len = 1;
    while(temp->next){
        len++;
        temp = temp->next;
    }
    for(int i=0; i<len; i++){
        temp = head;
        for(int j=0; j<len-i-1; j++){
            if((temp->data) > (temp->next->data)){
                swap(temp->data, temp->next->data);
            }
            temp = temp->next;
        }
    }
    return head;
}
 
