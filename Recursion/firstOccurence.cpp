//first occurence: Find the index of the first occurence of given element in an array.
//Time Compexity: O(n)
//Space Compelxity: O(n)
#include<iostream>
using namespace std;

int firstOccurence(int arr[], int n, int key) {
    //base case
    if(n == 0){
        return -1;
    }
    //recursive case
    if(arr[0] == key){
        return 0;
    }
    int subIdx = firstOccurence(arr + 1, n-1, key);
    if(subIdx != -1){
        return ++subIdx;
    }
    return -1;

}

int main() {
    int arr[] = {1, 2, 3, 5, 2, 5};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;
    cout << firstOccurence(arr, n, key); 
    return 0;
}