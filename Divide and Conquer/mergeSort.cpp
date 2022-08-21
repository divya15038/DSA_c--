//merge sort: Merge sort is used to sort an array based on the technique of divide and conquer. 
//Time Complexity: O(nlogn)
//Space Complexity: O(n)
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int start, int end){
    int i = start;
    int mid = (start+end)/2;
    int j = mid + 1;
    vector<int> temp;

    //to compare elements of the two subarrays
    while(i<=mid and j<=end){
        if(v[i] > v[j]){
            temp.push_back(v[j]);
            j++;
        } else {
            temp.push_back(v[i]);
            i++;
        }
    }

    //copy any remaining elements from left subarray
    while(i<=mid){
        temp.push_back(v[i++]);
    }

    //copy any remaining elements from right subarray
    while(j<=end){
        temp.push_back(v[j++]);
    }

    //copy elements from temp to v
    int k = 0;
    for(int i = start; i<=end; i++){
        v[i] = temp[k++];
    } 
    return;
}

void mergeSort(vector<int> &v, int start, int end){
    //base case
    if(start>=end){
        return ;
    }
    //recursive case
    int mid = (start + end)/2;
    mergeSort(v, start, mid);
    mergeSort(v, mid + 1, end);
    return merge(v, start, end);
}

int main() {
    vector<int> v = {10, 5, 2, 7, 6, 0, 4};
    mergeSort(v, 0, v.size()-1);

    for(auto x: v){
        cout << x << " ";
    }
    return 0;
}