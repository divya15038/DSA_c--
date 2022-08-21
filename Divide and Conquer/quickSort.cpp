//quick sort: Select a pivot element, then insert it into the right position, creating two partitions, recursively repeat the same steps
//for right and left subarray
//Time Complexity: O(nlogn) - average time complexity O(n^2)
//Space complexity: O(logn) O(n)-worst case
#include<bits/stdc++.h>
using namespace std;

int quickSortPartition(vector<int> &v, int start, int end){
    int i = start - 1;
    int pivot = v[end];

    for(int j=start; j<end; j++){
        if(v[j] < pivot){
            i++;
            swap(v[j], v[i]);
        }
    }
    swap(v[i+1], v[end]);
    return i+1;
}

void quickSort(vector<int> &v, int start, int end) {
    //base case
    if(start >= end){
        return ;
    }
    //recursive case
    int p = quickSortPartition(v, start, end);
    quickSort(v, start, p-1);
    quickSort(v, p+1, end);
    return;
}

int main() {
    vector<int> v = {10, 5, 2, 7, 6, 0, 4};
    quickSort(v, 0, v.size()-1);

    for(auto x: v){
        cout << x << " ";
    }
    return 0;
}