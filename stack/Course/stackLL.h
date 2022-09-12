template<typename T>
class Stack;

template<typename T>
class Node{
public:
    T data;
    Node* next;
    Node(T d):data(d),next(NULL){};
};

template<typename T>
class Stack{
    Node<T>* head;
public:
    Stack() {
        head = NULL;
    }

    void push(T d){
        Node<T>* temp = new Node<T>(d);
        temp->next = head;
        head = temp;
    }

    bool empty(){
        return head == NULL;
    }

    T top(){
        return head->data;
    }

    void pop(){
        if(head!=NULL){
            Node<T> * temp = head;
            head = head->next;
            delete temp;
        }
    }
};

