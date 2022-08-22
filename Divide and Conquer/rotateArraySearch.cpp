//rotate array search: We are given an array such that it is a sorted array rotated about a pivot point. Find an efficient searching 
//algorithm to search through the element
//To do, find the smallest index in case of duplicates
//Time Complexity: O(logn)
//Space Complexity: O(1)
#include<bits/stdc++.h>
using namespace std;

int rotateArraySearch(vector<int> v, int n, int key) { // 3 4 3 3 3 3
    int s = 0;
    int e = n - 1;
    int m = (s+e)/2;

    //2 cases
    while(s<=e){
        //element lies of L1 if it is bigger than start
        if(v[m] == key){
            return m;
        } 
        //edge case
        if((v[s] == v[m]) and (v[m] == v[e])){
            s++;
            e--;
        }
        //lies on L1
        else if(v[m] >= v[s]){
            //2 cases
            //lies between start and mid-1
            if(v[s] <= key and key <= v[m]){
                e = m - 1;
            }
            //lies between mid + 1 to end
            else {
                s = m + 1;
            }
        }
        //lies on L2 
        else {
            //2 cases
            //lies between mid+1 and end
            if(v[m] <= key and key <= v[e]){
                s = m + 1;
            }
            //lies between start and mid-1
            else {
                e = m - 1;
            }
        }
        //edge cases
        
        m = (s+e)/2;

        //cout << "okay" << endl;
    }
    return -1;
}


int main() {
    vector<int> v= {3, 3 ,3 , 2, 3};

    int key;
    cin >> key;
    int idx = rotateArraySearch(v, v.size(),key);
    if(idx != -1){
        cout << key << " is present at index " << idx << endl;
    } else {
        cout << key << " is not present in the array" << endl;
    }
    return 0;
}