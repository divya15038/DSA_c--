//lower bound: Find the lower bound of a given value in a sorted array. If value in array, then return value, otherwise return the next smallest integer in array.
//If the value is smaller than the first element in array, return -1.
#include<bits/stdc++.h>
using namespace std;


int lowerBound(vector<int> A, int Val) {
    // your code goes here
    if(Val < A[0]){
        return -1;
    }
    int s = 0;
    int e = A.size() - 1;
    int mid = (s+e)/2;
    while(s<=e){
        if(A[mid] == Val){
            return A[mid];
        }
        else if(Val > A[mid]){
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = (s+e)/2;
    }
    return A[mid];
}

int main() {
    vector<int> a = {-1, -1, 2, 3, 4 ,5};
    int key;
    cin >> key;
    cout << lowerBound(a, key);
}