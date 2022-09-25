#include<vector>
#include<iostream>
using namespace std;

class Heap {
    vector<int> v;

    void heapify(int index) {
        int left = 2*index;
        int right = 2*index + 1;

        int minIdx = index;
        if(left < v.size() and v[minIdx] > v[left]){
            minIdx = left;
        }
        if(right < v.size() and v[minIdx] > v[right]){
            minIdx = right;
        }

        if(minIdx != index){
            swap(v[minIdx], v[index]);
            heapify(minIdx);
        }
    }
public:
    Heap(int size){
        v.reserve(size + 1);
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);
        int idx = v.size() -1;
        int parent = idx/2;

        while(idx > 1 and v[idx] < v[parent]){
            swap(v[idx], v[parent]);
            idx = parent;
            parent = idx/2;
        }
    }

    void pop() {
        //step 1- swap(first and last)
        if(v.size() == 2){
            v.pop_back();
            return;
        } else if(v.size() == 1){
            cout << "No element to pop." << endl;
            return;
        }
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        
        if(v.size() > 3){
            heapify(v);            
        }else {
            if(v[1] > v[2]){
                swap(v[1], v[2]);
            }
        }
        return;
    }

    void heapify(vector<int> &v) {
        int parent = 1;
        int min_idx = min(2*parent, 2*parent+1);
        while(parent < v.size()-1 and v[parent] > v[min_idx]){
            swap(v[min_idx], v[parent]);
            parent = min_idx;
            min_idx = min(2*parent, 2*parent+1);
        }
    }
};