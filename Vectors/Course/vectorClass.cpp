#include<iostream>
using namespace std;
template<typename T>
class Vector {

    //data properties
    T * arr;
    int cs;
    int ms;

    public:
    //methods, constructor
    Vector (int size = 0) {
        cs = size;
        ms = size == 0? 1:size;
        arr = new T[ms];
    }

    void push_back(int n) {
        //check if the vector is full
        if(cs == ms){
            T *temp = arr;
            ms = 2*ms;
            arr = new T[ms];
            for(int i=0; i<cs; i++){
                arr[i] = temp[i];
            }
            delete []temp;
        } 
        arr[cs] = n;
        cs++;
    }

    T pop_back() {
        //check if the vector is empty
        if(cs == 0){
            cout << "No element to pop";
            return -1;
        }
        cs--;
        return arr[cs];
    }

    T front() const{
        //check if the vector is empty
        if(cs == 0){
            cout << "Vector is empty, no value to show";
            return -1;
        }
        return arr[0];
    }

    T back() const{
        //check if the vector is empty
        if(cs == 0){
            cout << "Vector is empty, no value to show";
            return -1;            
        }
        return arr[cs-1];
    }

    T at(int idx) const{
        if(cs == 0){
            cout << "Vector is empty, no value to show";
            return -1;            
        }
        return arr[idx];        
    }

    T size() const{
        return cs;
    }

    T capacity() const{
        return ms;
    }

    T operator[](int idx) const{
        return arr[idx];
    }
};

int main() {
    Vector<int> v;
    v.push_back(1);
    cout << v.size() << " ";
    cout << v.capacity() << " ";
    v.push_back(2);
    cout << v.size() << " ";
    cout << v.capacity() << " ";
    v.push_back(3);
    cout << v.size() << " ";
    cout << v.capacity() << " ";
    cout << v.back() << " ";
    v.pop_back();
    cout << v.back() << " ";
    cout << v[0] << " ";
    return 0;
}