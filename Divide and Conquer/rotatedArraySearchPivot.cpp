//rotated array search using a pivot: 1. Find the pivot element about which the sorted array is rotated.
//2. aplly binary search to the remaining sorted parts of the array.
//Time Complexity: O(logn)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v, int key, int s, int e){
    //base case
    if(s>e){
        return -1;
    }
    //recursive case
    int mid = (s + e)/2;
    if(v[mid] == key){
        return mid;
    }
    if(v[mid] > key){
        return binarySearch(v, key, 0, mid-1);
    }
    return binarySearch(v, key, mid+1, e);
}
int findPivot(vector<int> &v, int start, int end) { 
    //base cases
    if(start > end){
        return -1;
    }
    if(start == end){
        return start;
    }
    //recursive cases
    int mid = (start+end)/2;
    //if the middle element is smaller than middle + 1, that means pivot lies towards right
    if(mid < end and v[mid] > v [mid+1]){
        return mid+1;
    } else if(mid > start and v[mid] < v[mid-1]){
        return mid;
    } else if(v[start] >= v[mid]){
        return findPivot(v, start, mid - 1);
    } 
    return findPivot(v, mid+1, end);
}

int rotatedBinarySearch(vector<int> v, int n,int key) {
    int pivot = findPivot(v, 0, n - 1);
    //if pivot is not found, the array is already sorted, apply binary search to the array
    if(pivot == -1){
        return binarySearch(v, key, 0, n-1);
    }
    if(v[pivot] == key){
        return pivot;
    }
    else if(v[0] > key){
        return binarySearch(v, key, pivot+1, n-1);
    }
    return binarySearch(v, key, 0, pivot-1);
}

int main() {
    vector<int> v = {3, 4, 5, 6, 1, 2};
    int key;
    cin >> key;
    int idx = rotatedBinarySearch(v, v.size(), key);
    if(idx != -1){
        cout << key << " was found at index " << idx << endl;
    } else {
        cout << key << " was not found in the array";
    }
    return 0;
}