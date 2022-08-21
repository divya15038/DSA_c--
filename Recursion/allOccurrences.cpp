//all occurrences: find all occurences of an element in the given array.
//Time complexity: O()
//Space complexity: O()
#include<iostream>
#include<vector>
using namespace std;

//Time Complexity: O(n)
//Space Complexity: O(n)
vector<int> res;
int allOccurences(int arr[], int n, int key){
    //base case
    if(n == 0){
        return -1;
    }
    //recursive case
    if(arr[n-1] == key){
        res.push_back(n-1);
        //cout << n-1 << endl;
    }
    allOccurences(arr, n-1, key);
    return 0;
}

int main(){
    int arr[] = {1, 2, 3, 5, 2, 5};
    int n = sizeof(arr)/sizeof(int);

    int key;
    cin >> key;
    allOccurences(arr, n, key);
    if(res.size()){
        for(auto x: res){
            cout << x << " ";
        }
    } else {
        cout << "-1" << endl;
    }
    return 0;
}