//subset sum queries: Given an array of integers and N queries, return a vector of boolean values that tells if a subset summing up to the 
//element in the query exists or not.
//Time Complexity: O(1) for resolving each query
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

vector<bool> subsetSumQueries(vector<int> arr, vector<int> query) {
    bitset<100> bit;
    vector<bool> bl;
    bit.reset();
    bit[0] = 1; //every array has a subset sum of 0;

    for(int i=0; i<arr.size(); i++){
        bit = bit | (bit << arr[i]); 
    }

    for(int i=0; i<query.size(); i++){
        bl.push_back(bit[query[i]] == 0? 0:1);
    }
    return bl;
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> query = {5, 3, 8};

    vector<bool> b = subsetSumQueries(arr, query);
    for(auto x: b){
        cout << x << " ";
    }
    return 0;
}