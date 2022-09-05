#include<iostream>
using namespace std;
class List;

class Node {
    int data;
    Node* next;
public:
    Node(int d):data(d),next(NULL){}
    
    ~Node(){
        if(next != NULL){
            delete next; //recursive calls till end of linked list, deleted in reverse order
        }
    }
    
    friend class List;
};


class List {
    Node* head;
    Node* tail;
public:
    List():head(NULL), tail(NULL){}

    void push_front(int data){
        Node* n = new Node(data);
        if(head == NULL){
            head = tail = n;
            return;
        }
        n->next = head;
        head = n;
    }

    void push_back(int data){
        Node* n = new Node(data);
        if(tail == NULL){
            push_front(data);
            return;
        }
        tail->next = n;
        tail = n;
        return;
    }

    void print(){
        if(head == NULL){
            cout << "The list is empty";
            return;
        }
        Node* temp = head;
        while(temp != NULL){
            cout << temp->data;
            temp->next != NULL? cout<< "->": cout << endl;
            temp = temp->next;
        }
        delete temp;
        return;
    }

    int len() {
        if(head == NULL){
            return 0;
        }
        Node* temp = head;
        int count = 0;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insert(int data, int pos) {
        if(pos>=len() or pos<0){
            cout << "Please enter a valid position" << endl;
            return;
        }
        if(pos == 0){
            push_front(data);
            return;
        }
        if(pos == len()-1){
            push_back(data);
            return ;
        }
        Node* n = new Node(data);
        Node* temp = head;
        Node* prev;
        while(pos != 0){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        prev->next = n;
        n->next = temp;
        return;
    }

    int search(int key){
        Node* temp = head;
        int pos = 0;
        while(temp != NULL){
            if(temp->data == key){
                return pos;
            }
            pos++;
            temp = temp->next;
        }
        return -1;
    }

    int helperRecursiveSearch(int key, Node* head){
        //base case
        if(head == NULL){
            return -1;
        }
        //recursive case
        if(head->data == key){
            return 0;
        }
        int idx = helperRecursiveSearch(key, head->next);
        if(idx != -1){
            return ++idx;
        }
        return -1;
    }

    int recursiveSearch(int key){
        return helperRecursiveSearch(key, head);
    }

    int pop_front(){
        if(head == NULL){
            cout << "Nothing to remove in linked list" << endl;
            return -1; 
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        int data = temp->data;
        delete temp;
        return data;
    }

    int pop(int pos){
        if(pos>=len() or pos<0){
            return -1;
        }
        if(pos == 0){
            return pop_front();
        }
        Node* temp = head;
        Node* prev;
        while(pos != 0){
            prev = temp;
            temp = temp->next;
            pos--;
        }
        prev->next = temp->next;
        temp->next = NULL;
        int data = temp->data;
        delete temp;
        return data;
    }

    ~List(){
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }
};