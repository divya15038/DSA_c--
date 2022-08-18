//insertion sort: Insert the element at the right place in a sorted array. Consider two parts of array, sorted and unsorted and place elements accordingly in sorted part from unsorted part.
//Time Complexity: O(n^2)

#include<iostream>
using namespace std;

void insertionSort(int *arr, int n){
    for(int i=1; i<n; i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev + 1] = curr;
    }
}

int main() {
    int arr[] = {34, 12, 22, 56, 98, 45};
    int n = sizeof(arr)/sizeof(int);

    bool flag = true;
    for(int i=0; i<n; i++){
        if(arr[i] > arr[i+1]){
            flag = false;
            break;
        }
    }

    if(!flag) {
        insertionSort(arr, n);
    }

    for(auto x: arr){
        cout << x << " ";
    }
}