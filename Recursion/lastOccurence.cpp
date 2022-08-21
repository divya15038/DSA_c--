//Find the index of last occurence of an element in the given array using a recursive function.
//Time complexity: O(n)
//Space Cmplexity: O(n)
#include<iostream>
using namespace std;

int lastOccurence(int arr[], int n, int key){
    //base case
    if(n == 0){
        return -1;
    }
    //recursive case
    if(arr[n-1] == key){
        return n-1;
    }
    int SubIdx = lastOccurence(arr, n-1, key);
    if(SubIdx==-1){
        return -1;
    }
    return SubIdx;
}

int lastOccurenceTwo(int arr[], int n, int key) {
    //base case
    if(n == 0){
        return -1;
    }
    //recursive case
    int subIdx = lastOccurenceTwo(arr+1, n-1, key);
    if(subIdx != -1){
        return ++subIdx;
    }
    if(arr[0] == key){
        return 0;
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 2, 5};
    int n = sizeof(arr)/sizeof(n);

    int key; 
    cin >> key;
    cout << lastOccurence(arr, n, key);  
    cout << " " << lastOccurenceTwo(arr, n, key);
    return 0;
}