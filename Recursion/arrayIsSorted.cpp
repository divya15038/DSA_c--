//Write a recursive function to check if the array is sorted or not.
//Time Complexity: O(n)
//Space Complexity: O(n)
#include<iostream>
using namespace std;

bool isSortedArray(int arr[], int size){
    //base case
    if(size == 1){
        return true;
    }
    //recursive case
    if(arr[0] <= arr[1] && isSortedArray(arr + 1, size-1)){
        return true;
    }
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 2};
    int n = sizeof(arr)/sizeof(n);

    cout << isSortedArray(arr, n);
    return 0;
}