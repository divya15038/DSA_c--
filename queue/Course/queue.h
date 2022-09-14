template<typename T>
class Queue{
    T *arr;
    int ms;
    int cs;
    int front;
    int rear;

public:
    Queue(int default_size=5){
        ms = default_size;
        cs = 0;
        front = 0;
        rear = ms-1;
        arr = new T[ms];
    }

    bool isFull(){
        return cs == ms;
    }

    void push(T data){
        if(!isFull()){
            rear = (rear+1)%ms;
            arr[rear] = data;
            cs++;
        }
    }

    bool isEmpty() {
        return cs == 0;
    }

    void pop(){
        if(!isEmpty()){
            front = (front+1)%ms;
            cs--;
        }
    }

    T getFront(){
        if(!isEmpty()){
            return arr[front];
        }
    }
};