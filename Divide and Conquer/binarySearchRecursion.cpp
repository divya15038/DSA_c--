//binary search recursion: Implement binary search on sorted array using recursion.
//Time Complexity: O(logn)
//Space Complexity: O(logn)
#include<bits/stdc++.h>
using namespace std;

int binarySearchRecursive(vector<int> v, int key, int start, int end){
    //base case
    if(start > end){
        return -1;
    }
    //recursive case
    int mid = (start+end)/2;
    if(v[mid] == key){
        return mid;
    } else if(v[mid] > key){
        return binarySearchRecursive(v, key, start, mid-1);
    } else {
        return binarySearchRecursive(v, key, mid+1, end);
    }
}

int main(){
    vector<int> v = {1, 4, 6, 23, 45};
    
    int key;
    cin >> key;
    int idx = binarySearchRecursive(v, key, 0, v.size()-1);
    if(idx != -1){
        cout << key << " is present at index " << idx;
    } else {
        cout << key << " is not present in the array";
    }
    return 0;
}