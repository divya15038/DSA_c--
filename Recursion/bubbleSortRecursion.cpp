//for practice: to convert iterative code to recursive code
#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n){
    //base case
    if(n == 0){
        return;
    }
    //recursive case
    for(int i=1; i<n; i++){
        if(arr[i]<arr[i-1]){
            swap(arr[i], arr[i-1]);
        }
    }
    bubbleSort(arr, n-1);
    return;
}

void bubbleSort2(int arr[], int n, int j){
    //base case
    if(n==1){
        return;
    }
    //recursive case
    //outer loop
    if(j==n-1){
        bubbleSort2(arr, n-1, 0);
        return;
    }

    //inner loop
    if(arr[j] > arr[j+1]){
        swap(arr[j], arr[j+1]);
    }
    bubbleSort2(arr, n, j+1);
    return;
}
int main(){
    int arr[] = {12, 2, 41, 22, 76, 3};
    int n = sizeof(arr)/sizeof(int);

    bubbleSort2(arr, n, 0);
    for(auto x: arr){
        cout << x << " ";
    }
    return 0;
}