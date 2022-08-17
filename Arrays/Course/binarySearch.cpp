//binary Search: Time Complexity: log2(n)
#include<iostream>
using namespace std;

int binarySearch(int * arr, int n, int key) {
    int start = 0;
    int end = n-1;
    int mid = (start + end)/2;
    while(start <= end) {
        if(arr[mid] == key){
            return mid;
        } else if(arr[mid] < key){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    return -1;
}

int main() {
    int arr[] = {12, 45, 67, 89, 90, 120};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;
    int index= binarySearch(arr, n, key);

    if(index!=-1){
        cout << key << " found at index " << index;
    } else {
        cout << key << " not found in the given array";
    }
    return 0;
}