//selection sort: Find the minimum element in the unsorted part of the array and insert it at the end of sorted part of the array. 
//Time complexity: O(n^2)

#include<iostream>
using namespace std;

void selectionSort(int *arr, int n){
    for(int i=0; i<n-1; i++){
        int min_pos = i;
        
        //find the minimum element in unsorted array
        for(int j=i; j<n; j++){
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        swap(arr[min_pos], arr[i]);
    }
}

int main() {
    int arr[] = {23, 45, 11, 26, 2, 78, 34};
    int n = sizeof(arr)/sizeof(int);

    bool flag = true;
    for(int i=0; i<n-1; i++){
        if(arr[i] > arr[i+1]){
            flag = false;
            break;
        }
    }

    if(!flag){
        selectionSort(arr, n);
    }

    for(auto x: arr){
        cout << x << " ";
    }
    return 0;
}